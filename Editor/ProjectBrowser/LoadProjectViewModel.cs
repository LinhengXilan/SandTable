/// @file ProjectBrowser/LoadProjectViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.10
/// @date 2025-5-24

using Editor.Core;
using Editor.ProjectBrowser.Project;
using Editor.Utility;
using System.Collections.ObjectModel;
using System.IO;

namespace Editor.ProjectBrowser {
	public class LoadProjectViewModel : ViewModelBase {
		public RelayCommand NewProjectButtonCommand {
			get;
		}
		
		private const string _ProjectInfoFile = "Data/ProjectInfos.xml";

		private static readonly ObservableCollection<ProjectInfo> _ProjectInfos = new();
		
		public ReadOnlyObservableCollection<ProjectInfo> ProjectInfos {
			get;
		}

		public LoadProjectViewModel(ProjectBrowserViewModel projectBrowserViewModel) {
#region 初始化
			NewProjectButtonCommand = new RelayCommand(() => {
					projectBrowserViewModel.CurrentViewModel = projectBrowserViewModel.NewProjectViewModel;
				}
			);
			
			ProjectInfos = new(_ProjectInfos);
#endregion
			
			var projectInfoFilePath = Path.GetDirectoryName(_ProjectInfoFile)!;

			if (!Path.Exists(projectInfoFilePath)) {
				Directory.CreateDirectory(projectInfoFilePath);
			}

			var projectInfos = Serializer.XmlFromFile<List<ProjectInfo>>(_ProjectInfoFile);
			if (projectInfos == null) {
				return;
			}
			
			foreach (var projectInfo in projectInfos) {
				_ProjectInfos.Add(projectInfo);
			}
		}
		
		/// <summary>
		/// 更新项目列表并打开项目
		/// </summary>
		/// <param name="path">项目文件的路径</param>
		public static void LoadProject(string path) {
			if (!File.Exists(path)) {
				return;
			}
			
			var project = Serializer.XmlFromFile<Project.Project>(path);
			if (project == null) {
				return;
			}
			
			var projectPath = Path.GetDirectoryName(path)!;

			var projectInfo = _ProjectInfos.FirstOrDefault(x => x.Path == path);
			if (projectInfo == null) {
				_ProjectInfos.Add(
					new ProjectInfo() {
						Name = project.Name,
						Path = path,
						IconPath = $@"{projectPath}\Content\icon.ico"
					}
				);
			} else {
				projectInfo.Name = project.Name;
				projectInfo.Path = path;
				projectInfo.IconPath = $@"{projectPath}\Content\icon.ico";
			}
			
			Serializer.XmlToFile(_ProjectInfoFile, _ProjectInfos);
		}
	}
}