/// @file ProjectBrowser/NewProjectViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using Editor.Core;
using Editor.ProjectBrowser.Project;
using Editor.Utility;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;

namespace Editor.ProjectBrowser {
	public class NewProjectViewModel : ViewModelBase {
		public RelayCommand ReturnButtonClickedCommand {
			get;
		}
		
		public RelayCommand CreateButtonClickedCommand {
			get;
		}
		
		public ProjectTemplate ProjectTemplateListBoxSelectedItem {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ProjectTemplateListBoxSelectedItem));
				}
			}
		}

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
		
		public string ProjectPath {
			get;
			set {
				if (field != value) {
					field = value;
					ValidateProjectString();
					OnPropertyChanged(nameof(ProjectPath));
				}
			}
		} = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\SandTable\Projects\";
		
		private const string _TemplatePath = "ProjectTemplates";
		
		private ObservableCollection<ProjectTemplate> _ProjectTemplates = new();
		
		public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates {
			get;
		}
		
		public static bool IsStringValid = false;
		
		public string ErrorMessage {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ErrorMessage));
				}
			}
		} = string.Empty;
		
		private void ValidateProjectString() {
			string path = ProjectPath;
			
			if (!Path.EndsInDirectorySeparator(path)) {
				path += Path.DirectorySeparatorChar;
			}
			
			path += $@"{ProjectName}\";
			IsStringValid = false;
			if (string.IsNullOrEmpty(ProjectName.Trim())) {
				ErrorMessage = "项目名不能为空";
			} else if (string.IsNullOrWhiteSpace(ProjectName.Trim())) {
				ErrorMessage = "项目名不能含有空格";
			} else if (ProjectName.IndexOfAny(Path.GetInvalidFileNameChars()) != -1) {
				ErrorMessage = "项目名不能包含特殊字符";
			} else if (string.IsNullOrEmpty(ProjectPath.Trim())) {
				ErrorMessage = "项目路径不能为空";
			} else if (ProjectPath.IndexOfAny(Path.GetInvalidPathChars()) != -1) {
				ErrorMessage = "项目路径不能包含特殊字符";
			} else if (Directory.Exists(path) && Directory.EnumerateFileSystemEntries(path).Any()) {
				ErrorMessage = "项目路径已存在且不为空";
			} else {
				ErrorMessage = string.Empty;
				IsStringValid = true;
			}
		}

		public NewProjectViewModel(ProjectBrowserViewModel projectBrowserViewModel) {
#region 初始化
			ReturnButtonClickedCommand = new RelayCommand(() => {
				projectBrowserViewModel.CurrentViewModel = projectBrowserViewModel.LoadProjectViewModel;
			});
			
			CreateButtonClickedCommand = new RelayCommand(() => {
				CreateProject(ProjectTemplateListBoxSelectedItem!);
				projectBrowserViewModel.CurrentViewModel = projectBrowserViewModel.LoadProjectViewModel;
			});

			ProjectTemplates = new(_ProjectTemplates);
#endregion

			try {
				var templateFiles = Directory.GetFiles(_TemplatePath, "Template.xml", SearchOption.AllDirectories);
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
		
		public void CreateProject(ProjectTemplate template) {
			if (!IsStringValid) {
				return;
			}
			
			var projectFilePath = Project.Project.Create(_TemplatePath, template, ProjectName, ProjectPath);
			if (projectFilePath == null) {
				return;
			}

			LoadProjectViewModel.LoadProject(projectFilePath);
		}
	}
}