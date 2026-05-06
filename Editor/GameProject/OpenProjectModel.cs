/// <file> GameProject/OpenProjectModel.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.12 </version>
/// <date> 2026-5-6 </date>

using Editor.Core;
using Editor.Utilities;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Xml.Serialization;

namespace Editor.GameProject {
	/// <summary>
	/// 存储项目信息，类似于vs欢迎界面的项目列表
	/// </summary>
	public class ProjectInfo : ViewModelBase {
		public string ProjectName {
			get;
			set;
		} = string.Empty;
		public string ProjectPath {
			get;
			set;
		} = string.Empty;
		public DateTime LastModifiedTime {
			get;
			set;
		} = DateTime.Now;
		[XmlIgnore]
		public string ProjectIconPath {
			get;
			set;
		}
	}
	
	public class ProjectInfoList {
		public List<ProjectInfo> Data {
			get;
			set;
		} = [];
	}

	class OpenProjectModel {
		private static readonly string _DataPath = Path.Combine(Environment.CurrentDirectory, "Data");
		private static readonly string _ProjectInfoListPath = string.Empty;
		private static readonly ObservableCollection<ProjectInfo> _ProjectInfos = [];
		public static ReadOnlyObservableCollection<ProjectInfo> ProjectInfos {
			get;
		}
		private static void ReadProjectInfo() {
			if (!File.Exists(_ProjectInfoListPath)) {
				return;
			}
			var projectInfos = Serializer.FromXmlFile<List<ProjectInfo>>(_ProjectInfoListPath);
			_ProjectInfos.Clear();
			if (projectInfos == null) return;
			foreach (var info in projectInfos) {
				var project = Serializer.FromXmlFile<Project>(info.ProjectPath);
				if (project == null) return;
				info.ProjectIconPath = project.IconPath;
				_ProjectInfos.Add(info);
			}
		}
		private static void WriteProjectInfo() {
			var projects = _ProjectInfos.OrderBy(x => x.LastModifiedTime).ToList();
			Serializer.ToXmlFile(_ProjectInfos, _ProjectInfoListPath);
		}
		/// <summary>
		/// 打开项目
		/// </summary>
		/// <param name="projectPath">项目文件（.stproj）的路径</param>
		/// <returns>返回项目信息，以后可能会在这里直接打开编辑器</returns>
		public static Project? OpenProject(string projectPath) {
			var projectInfo = _ProjectInfos.FirstOrDefault(x => x.ProjectPath == projectPath);	// 查找要打开的文件是否存在列表中
			var project = Serializer.FromXmlFile<Project>(projectPath);	// 读取项目文件
			if (project == null) return null;
			if (projectInfo == null) {  // 不存在则创建新的项目信息并添加到列表中
				projectInfo = new ProjectInfo {
					ProjectName = project.Name,
					ProjectPath = projectPath,
					ProjectIconPath = project.IconPath,
					LastModifiedTime = DateTime.Now
				};
				_ProjectInfos.Add(projectInfo);
			} else {	// 若已存在则更新信息
				projectInfo.LastModifiedTime = DateTime.Now;
			}
			WriteProjectInfo();
			return new Project(projectInfo.ProjectPath);
		}
		static OpenProjectModel() {
			try {
				if (!Directory.Exists(_DataPath)) {
					Directory.CreateDirectory(_DataPath);
				}
				ProjectInfos = new ReadOnlyObservableCollection<ProjectInfo>(_ProjectInfos);
				_ProjectInfoListPath = Path.Combine(_DataPath, "ProjectInfo.xml");
				ReadProjectInfo();
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
	}
}
