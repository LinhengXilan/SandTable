/// @file ProjectBrowser/ProjectTemplate.cs
/// author LinhengXilan
/// @version 0.0.0.8
/// @date 2025-5-22

using Editor.Core;
using System.Xml.Serialization;

namespace Editor.ProjectBrowser.Project {
	public class ProjectTemplate : ViewModelBase {
		public string Type {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Type));
				}
			}
		} = string.Empty;
		
		public string Description {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Description));
				}
			}
		} = string.Empty;

		[XmlIgnore]
		public List<string> Folders = ["Source", "Binary", "Intermediate", "Content"];
	}
}