/// @file ProjectBrowser/LoadProjectViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.21
/// @date 2025-5-28

using Editor.Core;
using Editor.ProjectBrowser.Project;
using Editor.Utility;
using System.Collections.ObjectModel;
using System.IO;
using System.Windows;
using System.Windows.Input;

namespace Editor.ProjectBrowser {
	public class LoadProjectViewModel : ViewModelBase {
		public ICommand NewProjectButtonCommand {
			get;
		}

		private const string _ProjectInfoFile = "Data/ProjectInfos.xml";

		private static readonly ObservableCollection<ProjectInfo> _ProjectInfos = [];
		
		public ReadOnlyObservableCollection<ProjectInfo> ProjectInfos {
			get;
		}

		public LoadProjectViewModel(ProjectBrowserViewModel projectBrowserViewModel) {
#region 初始化
			NewProjectButtonCommand = new RelayCommand<object>(x => {
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
				projectInfo.Icon = ImageUtils.LoadIcon(Path.Combine(Path.GetDirectoryName(projectInfo.Path)!, @"Content\icon.ico"), 32);
				_ProjectInfos.Add(projectInfo);
			}
		}
		
		/// <summary>
		/// 更新项目列表
		/// </summary>
		/// <param name="path">项目文件的路径</param>
		public static bool UpdateProjectInfoList(string projectFilePath) {
			var projectInfo = _ProjectInfos.FirstOrDefault(x => x.Path == projectFilePath);

			if (!File.Exists(projectFilePath)) {
				var result = MessageBox.Show("项目文件不存在，是否从最近项目列表中删除此项目。", string.Empty, MessageBoxButton.YesNo);
				if (result == MessageBoxResult.Yes && projectInfo != null) {
					_ProjectInfos.Remove(projectInfo);
					Serializer.XmlToFile(_ProjectInfoFile, _ProjectInfos);
					return false;
				}
			}
			
			var project = Serializer.XmlFromFile<NewProject>(projectFilePath);
			if (project == null) {
				return false;
			}
			
			var projectPath = Path.GetDirectoryName(projectFilePath)!;

			if (projectInfo == null) {
				_ProjectInfos.Add(
					new() {
						Name = project.Name,
						Path = projectFilePath,
						Icon = ImageUtils.LoadIcon($@"{projectPath}\Content\icon.ico", 32),
						LastModifyTime = DateTime.Now
					}
				);
			} else {
				projectInfo.Name = project.Name;
				projectInfo.Path = projectFilePath;
				projectInfo.Icon = ImageUtils.LoadIcon($@"{projectPath}\Content\icon.ico", 32);
				projectInfo.LastModifyTime = DateTime.Now;
			}
			
			Serializer.XmlToFile(_ProjectInfoFile, _ProjectInfos);
			return true;
		}
	}
}