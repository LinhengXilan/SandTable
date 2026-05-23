/// @file Utility/WindowUtils.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Interop;

namespace Editor.Utility {
	public static class WindowUtils {
		private class WindowSize {
			public double Left, Top, Width, Height;
		}

		private static readonly ConditionalWeakTable<Window, WindowSize> _NormalStateMap = new();
		private static readonly ConditionalWeakTable<Window, object?> _HookAttached = new();

		public static void Enable(Window window) {
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
				var state = new WindowSize {
					Left = window.Left,
					Top = window.Top,
					Width = window.Width,
					Height = window.Height
				};
				_NormalStateMap.AddOrUpdate(window, state);

				var workArea = SystemParameters.WorkArea;

				window.WindowState = WindowState.Normal;
				window.Left = workArea.Left;
				window.Top = workArea.Top;
				window.Width = workArea.Width;
				window.Height = workArea.Height;
			} else {
				if (normalState != null) {
					window.Left = normalState.Left;
					window.Top = normalState.Top;
					window.Width = normalState.Width;
					window.Height = normalState.Height;
				}
				
				_NormalStateMap.Remove(window);
			}
		}
	}
}