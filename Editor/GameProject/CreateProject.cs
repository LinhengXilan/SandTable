/// <file> GameProject/CreateProject.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.6 </version>
/// <date> 2026-4-21 </date>

using Editor.Core;
using Editor.Utilities;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Windows;

namespace Editor.GameProject {
	[DataContract]
	class ProjectTemplate {
		[DataMember]
		public string ProjectType {
			get;
			set;
		}
		[DataMember]
		public string ProjectFile {
			get;
			set;
		}
		[DataMember]
		public List<string> Folders {
			get;
			set;
		}	
		[DataMember]
		public string Description {
			get;
			set;
		}
	}

	class CreateProject : ViewModelBase {
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
		} = "NewProject";

		public string ProjectPath {
			get;
			set {
				if (field != value) {
					field = value;
					ValidateProjectPath();
					OnPropertyChanged(nameof(ProjectPath));
				}
			}
		} = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\SandTable\Project\";

		public bool IsValid {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(IsValid));
				}
			}
		} = false;

		public string ErrorMessage {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(ErrorMessage));
				}
			}
		}

		private ObservableCollection<ProjectTemplate> _ProjectTemplates = new ObservableCollection<ProjectTemplate>();
		public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates {
			get;
		}

		private void ValidateProjectPath() {
			var path = ProjectPath;
			if (!Path.EndsInDirectorySeparator(path)) {
				path += $@"\";
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
			} else if (string.IsNullOrWhiteSpace(ProjectPath.Trim())) {
				ErrorMessage = "项目路径不能含有空格";
			} else if (ProjectPath.IndexOfAny(Path.GetInvalidFileNameChars()) != -1) {
				ErrorMessage = "项目路径不能包含特殊字符";
			} else if (Directory.Exists(path) && Directory.EnumerateFileSystemEntries(path).Any()) {
				ErrorMessage = "项目路径已存在且不为空";
			} else {
				ErrorMessage = string.Empty;
				IsValid = true;
			}
		}

		public CreateProject() {
			ProjectTemplates = new ReadOnlyObservableCollection<ProjectTemplate>(_ProjectTemplates);
			try {
				var templateFiles = Directory.GetFiles(_TemplatePath, "Template.xml", SearchOption.AllDirectories);
				Debug.Assert(templateFiles.Any());
				foreach (var file in templateFiles) {
					var template = Serializer.FromFile<ProjectTemplate>(file);
					_ProjectTemplates.Add(template);
				}
			}
			catch(Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
	}
}