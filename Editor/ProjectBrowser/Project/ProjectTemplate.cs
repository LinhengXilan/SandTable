/// @file ProjectBrowser/ProjectTemplate.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using System.Xml.Serialization;

namespace Editor.ProjectBrowser.Project {
	public class ProjectTemplate {
		public string Type {
			get;
			set;
		} = string.Empty;
		
		public string Description {
			get;
			set;
		} = string.Empty;
		
		[XmlIgnore]
		public List<string> Folders = ["Source", "Binary", "Intermediate", "Content"];
	}
}