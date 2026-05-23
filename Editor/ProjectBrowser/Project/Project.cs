/// @file ProjectBrowser/Project.cs
/// author LinhengXilan
/// @version 0.0.0.10
/// @date 2025-5-24

using Editor.Core;

namespace Editor.ProjectBrowser.Project {
	/// <summary>
	/// 创建项目需要的信息
	/// </summary>
	public class Project {
		public string Name = string.Empty;
		public string Path = string.Empty;
		public EngineVersion EngineVersion = new();
	}
}