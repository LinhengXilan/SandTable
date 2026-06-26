/// @file ProjectBrowser/LoadProject/LoadProjectViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.21
/// @date 2025-5-28

using Editor.Core;
using Editor.Editors.MainEditor;
using Editor.ProjectBrowser.Project;
using Editor.Utility;
using Microsoft.Win32;
using System.Collections.ObjectModel;
using System.IO;
using System.Windows;
using System.Windows.Input;

namespace Editor.ProjectBrowser.LoadProject {
	public class LoadProjectViewModel : ViewModelBase {
		private const string _ProjectInfoFile = "Data/ProjectInfos.xml";

		private static readonly ObservableCollection<ProjectInfo> _ProjectInfos = [];
		
		public ProjectInfo? SelectedProjectInfo {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(SelectedProjectInfo));
				}
			}
		}

		public ReadOnlyObservableCollection<ProjectInfo> ProjectInfos {
			get;
		}

		public ICommand NewProjectButtonCommand {
			get;
		}
		
		public ICommand ProjectInfoDoubleClicked {
			get;
		}

		public ICommand OpenProjectButtonClicked {
			get;
		}
		
		
		public LoadProjectViewModel(ProjectBrowserViewModel projectBrowserViewModel) {
#region 初始化
			NewProjectButtonCommand = new RelayCommand<object>(x => projectBrowserViewModel.CurrentViewModel = projectBrowserViewModel.NewProjectViewModel);
			ProjectInfoDoubleClicked = new RelayCommand<ProjectInfo>(_ProjectInfoDoubleClicked);
			OpenProjectButtonClicked = new RelayCommand<object>(x => _OpenProjectButtonClicked());
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
			
			var project = Serializer.XmlFromFile<Project.NewProject>(projectFilePath);
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
		
		
		private void _OpenProjectButtonClicked() {
			OpenFileDialog dialog = new() {
				Multiselect = false,
				Title = "打开项目",
				Filter = "SandTable项目文件|*.stproj"
			};
			if (dialog.ShowDialog() == true) {
				if (UpdateProjectInfoList(dialog.FileName)) {
					Editors.ProjectClass.Project.ProjectFilePath = dialog.FileName;
					OpenEditor();
				}
			}
		}
		
		private void _ProjectInfoDoubleClicked(ProjectInfo projectInfo) {
			if (SelectedProjectInfo == null) {
				return;
			}
			if (UpdateProjectInfoList(SelectedProjectInfo.Path)) {
				Editors.ProjectClass.Project.ProjectFilePath = SelectedProjectInfo.Path;
				OpenEditor();
			}
		}

		private static void OpenEditor() {
			if (Activator.CreateInstance<MainEditorWindow>() is not { } editor) {
				return;
			}
			var currentWindow = Application.Current.MainWindow;
			if (Application.Current.MainWindow is ProjectBrowserWindow) {
				Application.Current.MainWindow = editor;
				currentWindow?.Close();
				editor.Show();
			}
		}
	}
}