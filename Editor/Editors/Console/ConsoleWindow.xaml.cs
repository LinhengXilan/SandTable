/// @file Console/ConsoleWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.31
/// @date 2026-7-9

using Editor.Utility;
using System.Windows;
using System.Windows.Input;

namespace Editor.Editors.Console {
	public partial class ConsoleWindow : Window {
		public ConsoleWindow() {
			InitializeComponent();
			WindowUtils.Enable(this, WindowUtils.Option.Clip);
		}

		public void MinimizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowState = WindowState.Minimized;
		}

		public void MaximizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowUtils.Maximize(this);
		}

		public void CloseButtonClicked(object sender, RoutedEventArgs args) {
			Close();
		}

		public void MouseDrag(object sender, RoutedEventArgs args) {
			if (args is MouseButtonEventArgs { ClickCount: 1 }) {
				if (WindowUtils.IsMaximized(this)) {
					WindowUtils.MaximizeByMouseDrag(this, Mouse.GetPosition(this));
				}
				DragMove();
			}
		}

		void ClearButtonClicked(object sender, RoutedEventArgs args) {
			Logger.Clear();
		}

		void FilterButtonClicked(object sender, RoutedEventArgs args) {
			var filter = LogMessageType.None;
			if (ErrorButton.IsChecked == true) {
				filter |= LogMessageType.Error;
			}
			if (WarningButton.IsChecked == true) {
				filter |= LogMessageType.Warning;
			}
			if (InfoButton.IsChecked == true) {
				filter |= LogMessageType.Info;
			}
			Logger.SetFilter(filter);
		}
	}
}