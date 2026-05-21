/// @file ProjectBrowser/NewProjectPage.xaml.cs
/// author LinhengXilan
/// @version 0.0.0.8
/// @date 2025-5-22

using Editor.ProjectBrowser.Project;
using Microsoft.Win32;
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
			if (DataContext is not NewProjectViewModel projectModel) {
				return;
			}
			if (ProjectTemplateListBox.SelectedItem is not ProjectTemplate template) {
				return;
			}
			
			projectModel.CreateProject(template);
		}
		
		public void DirectoryBrowserButtonClicked(object sender, RoutedEventArgs args) {
			if (DataContext is not NewProjectViewModel projectModel) {
				return;
			}
			
			var dialog = new OpenFolderDialog {
				Multiselect = false,
				Title = "项目位置"
			};
			bool? result = dialog.ShowDialog();
			
			if (result == true) {
				projectModel.ProjectPath = dialog.FolderName;
			}
		}
	}
}
