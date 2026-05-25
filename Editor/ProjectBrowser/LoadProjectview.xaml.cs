/// @file ProjectBrowser/LoadProjectView.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

using Editor.Core.WindowMessage;
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
				LoadProject(dialog.FileName);
			}
		}
		
		public void ProjectInfoDoubleClicked(object sender, RoutedEventArgs args) {
			if (ProjectInfoListBox.SelectedItem is not ProjectInfo projectInfo) {
				return;
			}
			LoadProject(projectInfo.Path);
		}
		
		private void LoadProject(string projectFilePath) {
			if (LoadProjectViewModel.UpdateProjectInfoList(projectFilePath)) {
				Messenger.Send(new OpenNewWindowMessage(typeof(EditorWindow), projectFilePath));
			}
		}
	}
}