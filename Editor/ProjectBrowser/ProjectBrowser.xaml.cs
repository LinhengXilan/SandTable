/// @file ProjectBrowser/ProjectBrowser.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.2
/// @date 2025-5-16

using Editor.Core;
using System.Windows;

namespace Editor.ProjectBrowser
{
	public partial class ProjectBrowser : Window {
		public WindowOperator WindowOperator = new();

		public ProjectBrowser() {
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