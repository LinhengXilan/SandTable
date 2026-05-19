/// @file ProjectBrowser/NewProjectPage.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.6
/// @date 2025-5-19

using System.Windows;
using System.Windows.Controls;

namespace Editor.ProjectBrowser
{
	public partial class NewProjectPage : Page
	{
		public NewProjectPage()
		{
			InitializeComponent();
		}
		
		public void ReturnButtonClicked(object sender, RoutedEventArgs args) {
			NavigationService!.GoBack();
		}
		
		public void CreateButtonClicked(object sender, RoutedEventArgs args) {

		}
	}
}
