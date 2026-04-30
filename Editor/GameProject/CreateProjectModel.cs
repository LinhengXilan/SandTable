/// <file> GameProject/CreateProjectModel.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.10 </version>
/// <date> 2026-5-1 </date>

using Editor.Core;
using Editor.Utilities;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;

namespace Editor.GameProject {
	/// <summary>
	/// 项目模板的内容
	/// </summary>
	public class ProjectTemplate {
		public string ProjectType {
			get;
			set;
		} = string.Empty;
		/// <summary>
		/// 需要生成的文件夹
		/// </summary>
		public List<string> Folders {
			get;
			set;
		} = ["Content", "Plugin"];
		public string Description {
			get;
			set;
		} = string.Empty;
	}
	class CreateProjectModel : ViewModelBase {
		private readonly string _TemplatePath = "ProjectTemplates";
		
		public string ProjectName {
			get;
			set {
				if (field != value) {
					field = value;
					ValidateProjectPath();
					OnPropertyChanged(nameof(ProjectName));
				}
			}
#if DEBUG
		} = "TestProject";
#else
		} = "NewProject";
#endif
		public string ProjectPath {
			get;
			set {
				if (field != value) {
					field = value;
					ValidateProjectPath();
					OnPropertyChanged(nameof(ProjectPath));
				}
			}
#if DEBUG
		} = @"C:\Home\Code\Project\SandTable\Temp\Projects";
#else
		} = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\SandTable\Projects\";
#endif
		public bool IsValid {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(IsValid));
				}
			}
		} = false;
		public string? ErrorMessage {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ErrorMessage));
				}
			}
		}

		private ObservableCollection<ProjectTemplate> _ProjectTemplates = new();
		public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates {
			get;
		}

		private void ValidateProjectPath() {
			var path = ProjectPath;
			if (!Path.EndsInDirectorySeparator(path)) {
				path += Path.DirectorySeparatorChar;
			}
			path += $@"{ProjectName}\";
			IsValid = false;
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
				IsValid = true;
			}
		}

		// 未来可以直接复制现成模板
		public string CreateProject(ProjectTemplate template) {
			ValidateProjectPath();
			if (!IsValid) {
				return string.Empty;
			}
			ProjectPath = Path.Combine(ProjectPath, ProjectName);
			try {
				if (!Directory.Exists(ProjectPath)) {
					Directory.CreateDirectory(ProjectPath);
				}
				// 创建所有必要文件夹
				foreach (var folder in template.Folders) {
					Directory.CreateDirectory(Path.Combine(ProjectPath, folder));
				}
				// 生成项目文件
				var projectFilePath = Path.Combine(ProjectPath, $"{ProjectName}.stproj");
				//File.Create(projectFilePath);
				var projectFileData = new Project(ProjectName) {
					IconPath = Path.GetFullPath(Path.Combine(Path.Combine($"{_TemplatePath}", "Default"), "Icon.ico"))
				};
				Serializer.XmlToFile(projectFileData, projectFilePath, "stproj", "https://SandTable.com/Developer/Project");
				return ProjectPath;
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
				return string.Empty;
			}
		}

		public CreateProjectModel() {
			ProjectTemplates = new ReadOnlyObservableCollection<ProjectTemplate>(_ProjectTemplates);
			try {
				var templateFiles = Directory.GetFiles(_TemplatePath, "Template.xml", SearchOption.AllDirectories);
				Debug.Assert(templateFiles.Any());
				foreach (var file in templateFiles) {
					var template = Serializer.XmlFromFile<ProjectTemplate>(file);
					_ProjectTemplates.Add(template);
				}
				ValidateProjectPath();

				// 生成项目模板
				// var template = new ProjectTemplate();
				// template.ProjectType = "Empty Project";
				// template.Description = "Project which has no code generated";
				// Serializer.XmlToFile(template, "project.xml");
			}
			catch(Exception e) {

				Debug.WriteLine(e.Message);
			}
		}
	}
}