/// @file ProjectBrowser/LoadProjectPage.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.7
/// @date 2025-5-20

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
		
		public void OpenProjectButtonClicked(object sender, RoutedEventArgs args) {

		}
	}
}