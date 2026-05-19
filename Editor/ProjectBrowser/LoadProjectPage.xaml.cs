/// @file ProjectBrowser/LoadProjectPage.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.6
/// @date 2025-5-19

using System.Windows;
using System.Windows.Controls;

namespace Editor.ProjectBrowser
{
	public partial class LoadProjectPage : Page
	{
		public LoadProjectPage()
		{
			InitializeComponent();
		}

		public void NewProjectButtonClicked(object sender, RoutedEventArgs args) {
			NavigationService!.Navigate(new NewProjectPage());
		}
	}
}