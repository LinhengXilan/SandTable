/// @file ProjectBrowser/Project.cs
/// author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using Editor.Utility;
using System.Diagnostics;
using System.IO;

namespace Editor.ProjectBrowser.Project {
	/// <summary>
	/// 创建项目需要的信息
	/// </summary>
	public class Project {
		public string Name = string.Empty;
		public string Path = string.Empty;
		public uint EngineVersion = Core.EngineVersion.BuildVersion;
		
		public static string? Create(string projectTemplatePath, ProjectTemplate template, string name, string path) {
			var projectPath = System.IO.Path.Combine(path, name);
			try {
				if (!Directory.Exists(projectPath)) {
					Directory.CreateDirectory(projectPath);
				}
				
				// 创建所有必要文件夹
				foreach (var folder in template.Folders) {
					// 创建项目中文件夹
					var projectFolder = System.IO.Path.Combine(projectPath, folder);
					var templateFolder = System.IO.Path.Combine(System.IO.Path.Combine(projectTemplatePath, template.Type), folder);
					
					Directory.CreateDirectory(projectFolder);
					FileUtils.CopyFolder(templateFolder, projectFolder);
				}
				
				// 生成项目文件
				var projectFilePath = System.IO.Path.Combine(projectPath, $"{name}.stproj");
				var project = new Project() {
					Name = name,
					Path = projectPath
				};
				
				Serializer.XmlToFile(projectFilePath, project, "stproj", "https://SandTable.com/Developer/Project");
				return projectFilePath;
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
				return null;
			}
		}
		
		public void Load() {
			
		}
	}
}