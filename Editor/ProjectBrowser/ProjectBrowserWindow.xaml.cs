/// @file ProjectBrowser/ProjectBrowserWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using Editor.Utility;
using System.Windows;

namespace Editor.ProjectBrowser {
	
	public partial class ProjectBrowserWindow : Window {
		public ProjectBrowserWindow() {
			InitializeComponent();
			WindowUtils.Enable(this);
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