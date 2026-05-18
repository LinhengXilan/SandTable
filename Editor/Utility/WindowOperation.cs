/// @file Core/WindowOperation.cs
/// author LinhengXilan
/// @version 0.0.0.4
/// @date 2025-5-18

using System.Windows;

namespace Editor.Core {
	public class WindowOperator {
		public Rect WindowSize;
		public bool IsMaximized;

		public void Maximize(Window window) {
			if (IsMaximized) {
				window.Left = WindowSize.Left;
				window.Top = WindowSize.Top;
				window.Width = WindowSize.Width;
				window.Height = WindowSize.Height;
				IsMaximized = false;
			} else {
				WindowSize = new Rect(window.Left, window.Top, window.Width, window.Height);
				Rect bounds = SystemParameters.WorkArea;
				window.Left = bounds.Left;
				window.Top = bounds.Top;
				window.Width = bounds.Width;
				window.Height = bounds.Height;
				IsMaximized = true;
			}
		}
		
		public void Minimize(Window window) {
			window.WindowState = WindowState.Minimized;
		}
	}
}