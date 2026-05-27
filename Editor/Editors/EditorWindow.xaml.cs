/// @file EditorWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.19
/// @date 2025-5-28

using Editor.Utility;
using System.Windows;

namespace Editor.Editors {
	public partial class EditorWindow : Window {
		public EditorWindow() {
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
	}
}