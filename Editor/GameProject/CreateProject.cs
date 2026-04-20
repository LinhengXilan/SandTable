/// <file> GameProject/CreateProject.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.5 </version>
/// <date> 2026-4-20 </date>

using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using Editor.Core;
using Editor.Utilities;

namespace Editor.GameProject {
	class CreateProject : ViewModelBase {
		private string _Name = "NewProject";
		private string _Path = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\SandTable\Project\";
		private readonly string _TemplatePath = "ProjectTemplates";
		public string Name {
			get => _Name;
			set {
				if (_Name != value) {
					_Name = value;
					OnPropertyChanged(nameof(Name));
				}
			}
		}
		public string Path {
			get => _Path;
			set {
				if (_Path != value) {
					_Path = value;
					OnPropertyChanged(nameof(Path));
				}
			}
		}
		private ObservableCollection<ProjectTemplate> _ProjectTemplates = new ObservableCollection<ProjectTemplate>();
		public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates {
			get;
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
}