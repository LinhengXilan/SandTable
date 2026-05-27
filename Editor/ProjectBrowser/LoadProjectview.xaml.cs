/// @file ProjectBrowser/LoadProjectView.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.19
/// @date 2025-5-28

using Editor.Editors;
using Editor.ProjectBrowser.Project;
using Microsoft.Win32;
using System.Windows;
using System.Windows.Controls;

namespace Editor.ProjectBrowser {
	public partial class LoadProjectView : UserControl {
		public LoadProjectView() {
			InitializeComponent();
		}
		
		public void OpenProjectButtonClicked(object sender, RoutedEventArgs args) {
			OpenFileDialog dialog = new() {
				Multiselect = false,
				Title = "打开项目",
				Filter = "SandTable项目文件|*.stproj"
			};
			if (dialog.ShowDialog() == true) {
				if (LoadProjectViewModel.UpdateProjectInfoList(dialog.FileName)) {
					Editors.ProjectClass.Project.ProjectFilePath = dialog.FileName;
					OpenEditor();
				}
			}
		}

		public void ProjectInfoDoubleClicked(object sender, RoutedEventArgs args) {
			if (ProjectInfoListBox.SelectedItem is not ProjectInfo projectInfo) {
				return;
			}
			if (LoadProjectViewModel.UpdateProjectInfoList(projectInfo.Path)) {
				Editors.ProjectClass.Project.ProjectFilePath = projectInfo.Path;
				OpenEditor();
			}
		}
		
		private static void OpenEditor() {
			if (Activator.CreateInstance<EditorWindow>() is not EditorWindow editor) {
				return;
			}
			var currentWindow = Application.Current.MainWindow;
			if (Application.Current.MainWindow is ProjectBrowserWindow) {
				Application.Current.MainWindow = editor;
				currentWindow.Close();
				editor.Show();
			}
		}
	}
}