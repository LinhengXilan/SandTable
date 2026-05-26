/// @file Editors/ProjectClass/Project.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using Editor.Core;
using Editor.Utility;
using System.Diagnostics;
using System.Windows.Input;
using System.Xml.Serialization;

namespace Editor.Editors.ProjectClass {
	public class Project :ViewModelBase {
		public string Name {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Name));
				}
			}
		} = string.Empty;

		public string Path = string.Empty;
		public EngineVersion EngineVersion = new();

		[XmlIgnore]
		public static string ProjectFilePath = string.Empty;

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
		
		public static Project? Load(string projectFilePath) {
			var project = Serializer.XmlFromFile<Project>(projectFilePath);
			return project;
		}
		
		public void Save() {
			Serializer.XmlToFile(ProjectFilePath, this);
		}
		
		public void UnLoad() {
			Serializer.XmlToFile(ProjectFilePath, this);
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