/// @file ProjectBrowser/NewProject.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using Editor.Core;
using System.Xml.Serialization;

namespace Editor.ProjectBrowser.Project {
	/// <summary>
	/// 创建项目需要的信息
	/// </summary>

	[XmlRoot("Project")]
	public class NewProject {
		public string Name = string.Empty;
		public string Path = string.Empty;
		public EngineVersion EngineVersion = new();
	}
}