/// @file ProjectBrowser/ProjectBrowserWindow.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.5
/// @date 2025-5-19

using Editor.Utility;
using System.Windows;

namespace Editor.ProjectBrowser
{
	public partial class ProjectBrowserWindow : Window {
		public WindowOperator WindowOperator = new();

		public ProjectBrowserWindow() {
			InitializeComponent();
		}
		
		public void MinimizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowOperator.Minimize(this);
		}
		
		public void MaximizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowOperator.Maximize(this);
		}
		
		public void CloseButtonClicked(object sender, RoutedEventArgs args) {
			Close();
		}
	}
}