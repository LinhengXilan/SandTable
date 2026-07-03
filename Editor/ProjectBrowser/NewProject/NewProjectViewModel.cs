/// @file ProjectBrowser/NewProject/NewProjectViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.27
/// @date 2026-7-3

using Editor.Core;
using Editor.Editors.MainEditor;
using Editor.ProjectBrowser.LoadProject;
using Editor.ProjectBrowser.Project;
using Editor.Utility;
using Microsoft.Win32;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Input;

namespace Editor.ProjectBrowser.NewProject {
	public class NewProjectViewModel : ViewModelBase {
		public ProjectTemplate ProjectTemplateListBoxSelectedItem {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ProjectTemplateListBoxSelectedItem));
				}
			}
		} = new();

		public string ProjectName {
			get;
			set {
				if (field != value) {
					field = value;
					ValidateProjectString();
					OnPropertyChanged(nameof(ProjectName));
				}
			}
		} = "Untitled";
		
		public string ProjectSavePath {
			get;
			set {
				if (field != value) {
					field = value;
					if (!Path.EndsInDirectorySeparator(field)) {
						field += Path.DirectorySeparatorChar;
					}
					ValidateProjectString();
					OnPropertyChanged(nameof(ProjectSavePath));
				}
			}
		} = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\SandTable\Projects\";
		
		private const string _ProjectTemplatePath = "ProjectTemplates";
		
		private readonly ObservableCollection<ProjectTemplate> _ProjectTemplates = [];
		public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates {
			get;
		}
		
		private static bool _IsStringValid = false;
		
		public string ErrorMessage {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ErrorMessage));
				}
			}
		} = string.Empty;

		public ICommand ReturnButtonClickedCommand {
			get;
		}
		
		public ICommand CreateButtonClickedCommand {
			get;
		}
		
		public ICommand SelectFolderButtonClickedCommand {
			get;
		}



		public NewProjectViewModel(ProjectBrowserViewModel projectBrowserViewModel) {
#region 初始化
			ReturnButtonClickedCommand = new RelayCommand<object>(x => {
				projectBrowserViewModel.CurrentViewModel = projectBrowserViewModel.LoadProjectViewModel;
			});
			
			CreateButtonClickedCommand = new RelayCommand<object>(x => {
				if (!_IsStringValid) {
					return;
				}
				Editors.ProjectClass.Project.ProjectFilePath = CreateProject(ProjectTemplateListBoxSelectedItem);
				OpenEditor();
			});
			
			SelectFolderButtonClickedCommand = new RelayCommand<object>(x => {
				OpenFolderDialog dialog = new() {
					Title = "项目位置",
					Multiselect = false,
				};
				if (dialog.ShowDialog() == true) {
					ProjectSavePath = dialog.FolderName;
				}
			});

			ProjectTemplates = new(_ProjectTemplates);
#endregion

			try {
				var templateFiles = Directory.GetFiles(_ProjectTemplatePath, "Template.xml", SearchOption.AllDirectories);
				foreach (string file in templateFiles) {
					var template = Serializer.XmlFromFile<ProjectTemplate>(file);
					if (template != null) {
						_ProjectTemplates.Add(template);
					}
				}
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
		
		private void ValidateProjectString() {
			string path = ProjectSavePath + $@"{ProjectName}\";
			_IsStringValid = false;
			if (string.IsNullOrEmpty(ProjectName.Trim())) {
				ErrorMessage = "项目名不能为空";
			} else if (string.IsNullOrWhiteSpace(ProjectName.Trim())) {
				ErrorMessage = "项目名不能含有空格";
			} else if (ProjectName.IndexOfAny(Path.GetInvalidFileNameChars()) != -1) {
				ErrorMessage = "项目名不能包含特殊字符";
			} else if (string.IsNullOrEmpty(path.Trim())) {
				ErrorMessage = "项目路径不能为空";
			} else if (path.IndexOfAny(Path.GetInvalidPathChars()) != -1) {
				ErrorMessage = "项目路径不能包含特殊字符";
			} else if (Directory.Exists(path) && Directory.EnumerateFileSystemEntries(path).Any()) {
				ErrorMessage = "目标项目文件夹已存在且不为空";
			} else {
				ErrorMessage = string.Empty;
				_IsStringValid = true;
			}
		}
		
		private string CreateProject(ProjectTemplate template) {
			try {
				if (!Directory.Exists(ProjectSavePath)) {
					Directory.CreateDirectory(ProjectSavePath);
				}
				
				var projectPath = Path.Combine(ProjectSavePath, ProjectName);

				// 创建所有必要文件夹
				foreach (var folder in template.Folders) {
					// 创建项目中文件夹
					var projectFolder = Path.Combine(projectPath, folder);
					var templateFolder = Path.Combine(Path.Combine(_ProjectTemplatePath, template.Type), folder);
					
					Directory.CreateDirectory(projectFolder);
					FileUtils.CopyFolder(templateFolder, projectFolder);
				}
				
				// 生成项目文件
				var projectFilePath = Path.Combine(projectPath, $"{ProjectName}.stproj");
				var project = new Project.NewProject() {
					Name = ProjectName,
					Path = projectPath
				};
				
				Serializer.XmlToFile(projectFilePath, project, "stproj", "https://SandTable.com/Developer/Project");

				LoadProjectViewModel.UpdateProjectInfoList(projectFilePath);
				return projectFilePath;
			} catch(Exception e) {
				Debug.WriteLine(e.Message);
				return string.Empty;
			}
		}
		
		private void OpenEditor() {
			if (Activator.CreateInstance(typeof(MainEditorWindow)) is MainEditorWindow editor) {
				var currentWindow = Application.Current.MainWindow;
				if (Application.Current.MainWindow is ProjectBrowserWindow) {
					Application.Current.MainWindow = editor;
					currentWindow?.Close();
					editor.Show();
				}
			}
		}
	}
}