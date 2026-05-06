/// <file> GameProject/CreateProjectView.xaml.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.12 </version>
/// <date> 2026-5-6 </date>

using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Editor.GameProject {
	public partial class CreateProjectView : UserControl {
		public CreateProjectView() {
			InitializeComponent();
		}
		
		private void CreateButtonClicked(object sender, RoutedEventArgs args) {
			var projectModel = DataContext as CreateProjectModel;
			var projectPath = projectModel?.CreateProject(projectTemplateListBox.SelectedItem as ProjectTemplate);
			var result = false;
			if (!string.IsNullOrEmpty(projectPath)) {
				result = true;
				OpenProjectModel.OpenProject(Path.Combine(projectModel.ProjectPath, $@"{projectModel.ProjectName}\{projectModel.ProjectName}.stproj"));
			}
			var window = Window.GetWindow(this);
			if (window != null) {
				window.DialogResult = result;
				window.Close();
			}
		}
	}
}
