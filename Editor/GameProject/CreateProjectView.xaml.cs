/// <file> GameProject/CreateProjectView.xaml.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.7 </version>
/// <date> 2026-4-23 </date>

using System.Windows;
using System.Windows.Controls;

namespace Editor.GameProject {
	public partial class CreateProjectView : UserControl {
		public CreateProjectView() {
			InitializeComponent();
		}
		
		private void CreateButtonClicked(object sender, RoutedEventArgs args) {
			var projectModel = DataContext as CreateProjectModel;
			var projectPath = projectModel.CreateProject(projectTemplateListBox.SelectedItem as ProjectTemplate);
			bool result = false;
			var window = Window.GetWindow(this);
			if (!string.IsNullOrEmpty(projectPath)) {
				result = true;
			}
			window.DialogResult = result;
			window.Close();
		}
	}
}
