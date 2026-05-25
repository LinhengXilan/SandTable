/// @file Editors/Project/Project.cs
/// author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

using Editor.Core;
using Editor.Utility;
using System.Diagnostics;
using System.Windows.Input;
using System.Xml.Serialization;

namespace Editor.Editors.Project {
	/// <summary>
	/// 仅用于存储数据，不作为ViewModel。
	/// </summary>
	public class Project {
		public string Name = string.Empty;
		public string Path = string.Empty;
		public EngineVersion EngineVersion = new();

		[XmlIgnore]
		public string ProjectFilePath = string.Empty;
		[XmlIgnore]
		public StepRecorder StepRecorder {
			get;
		} = new();
		[XmlIgnore]
		public ICommand AddLevel {
			get;
			private set;
		}
		[XmlIgnore]
		public ICommand RemoveLevel {
			get;
			private set;
		}
		[XmlIgnore]
		public static Project? CurrentProject;
		
		public List<Level> Levels = [];
		
		public Project() {
			AddLevel = new RelayCommand<object>(x => {
				_AddLevel("New Level");
				var level = Levels.Last();
				var index = Levels.Count - 1;
				StepRecorder.Add(
					new Step(
					$"[Project] Add Level \"{level.Name}\"",
						() => _RemoveLevel(level),
						() => Levels.Insert(index, level)
					)
				);
			});
			
			RemoveLevel = new RelayCommand<Level>(x => {
				var index = Levels.IndexOf(x);
				_RemoveLevel(x);
				StepRecorder.Add(
					new Step(
						$"[Project] Remove Level \"{x.Name}\"",
						() => Levels.Insert(index, x),
						() => _RemoveLevel(x)
					)
				);
			});
		}
		
		public static void Load(string projectFilePath) {
			CurrentProject = Serializer.XmlFromFile<Project>(projectFilePath);
			if (CurrentProject == null) {
				return;
			}
			CurrentProject.ProjectFilePath = projectFilePath;
		}
		
		public static void UnLoad() {
			if (CurrentProject == null) {
				return;
			}
			Serializer.XmlToFile(CurrentProject.ProjectFilePath, CurrentProject);
			CurrentProject = null;
		}

		private void _AddLevel(string name) {
			Debug.Assert(!StringUtils.IsStringValid(name));
			Levels.Add(new(name));
		}
		
		private void _RemoveLevel(Level level) {
			Levels.Remove(level);
		}
	}
}