/// @file Utility/WindowUtils.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Interop;
using System.Windows.Media;

namespace Editor.Utility {
	public static class WindowUtils {
		private class WindowSize {
			public double Left, Top, Width, Height;
			public const int CornerRadius = 6;
		}

		[Flags]
		public enum Option {
			None = 0,
			Clip = 1 << 1
		}

		private static readonly ConditionalWeakTable<Window, WindowSize> _NormalStateMap = new();
		private static readonly ConditionalWeakTable<Window, object?> _HookAttached = new();
		private static Option _Option = Option.None;
		
		public static void Enable(Window window, Option option) {
			if (_HookAttached.TryGetValue(window, out _)) {
				return;
			}
			
			if (window.IsLoaded) {
				AttachHook(window);
			}
			else {
				window.Loaded += (sender, args) => AttachHook(window);
			}
			_HookAttached.Add(window, null);
			
			if (option.HasFlag(Option.Clip)) {
				_Option |= Option.Clip;
				var rectangleGeometry = new RectangleGeometry(new(0, 0, window.ActualWidth, window.ActualHeight), 6, 6);
				window.Clip = rectangleGeometry;
				window.SizeChanged += (sender, args) => {
					rectangleGeometry.Rect = new(0, 0, window.ActualWidth, window.ActualHeight);
				};
			}

		}
		
		// 外部使用
		public static void Maximize(Window window) {
			_Maximize(window);
		}
		
		// 处理消息
		private static void AttachHook(Window window) {
			if (PresentationSource.FromVisual(window) is HwndSource source) {
				source.AddHook(WndProc);
			}
			else {
				window.SourceInitialized += (_, _) => (PresentationSource.FromVisual(window) as HwndSource)?.AddHook(WndProc);
			}
		}

		private static IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled) {
			const int WM_NCLBUTTONDBLCLK = 0x00A3;
			const int HTCAPTION = 2;

			if (msg == WM_NCLBUTTONDBLCLK && wParam.ToInt32() == HTCAPTION) {
				if (HwndSource.FromHwnd(hwnd)?.RootVisual is Window window) {
					_Maximize(window);
					handled = true;
				}
			}
			return IntPtr.Zero;
		}

		// 内部实现
		private static void _Maximize(Window window) {
			bool hasNormalState = _NormalStateMap.TryGetValue(window, out var normalState);

			if (!hasNormalState) {
				_NormalStateMap.AddOrUpdate(
					window,
					new WindowSize {
						Left = window.Left,
						Top = window.Top,
						Width = window.Width,
						Height = window.Height,
					}
				);

				var workArea = SystemParameters.WorkArea;
				window.WindowState = WindowState.Normal;
				window.Left = workArea.Left;
				window.Top = workArea.Top;
				window.Width = workArea.Width;
				window.Height = workArea.Height;
				if (_Option.HasFlag(Option.Clip)) {
					window.Clip = null;
				}
			} else {
				if (normalState != null) {
					window.Left = normalState.Left;
					window.Top = normalState.Top;
					window.Width = normalState.Width;
					window.Height = normalState.Height;
					if(_Option.HasFlag(Option.Clip)) {
						window.Clip = new RectangleGeometry(new Rect(0, 0, normalState.Width, normalState.Height),
							WindowSize.CornerRadius, WindowSize.CornerRadius);
					}
				}
				
				_NormalStateMap.Remove(window);
			}
		}
	}
}