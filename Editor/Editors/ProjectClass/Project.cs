/// @file Editors/ProjectClass/Project.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using Editor.Core;
using Editor.Utility;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Windows.Input;
using System.Xml.Serialization;

namespace Editor.Editors.ProjectClass {
	public class Project :ViewModelBase {
		public static Project? CurrentProject;

		public string Name {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Name));
				}
			}
		} = string.Empty;

		public EngineVersion EngineVersion = new();

		[XmlIgnore]
		public static string ProjectFilePath = string.Empty;
		
		[XmlIgnore]
		public StepRecorder StepRecorder {
			get;
		} = new();

		[XmlIgnore]
		private ObservableCollection<Level> _Levels = [];

		[XmlIgnore]
		public ReadOnlyObservableCollection<Level> Levels {
			get;
		}

		[XmlIgnore]
		public Level? CurrentLevel {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(CurrentLevel));
				}
			}
		} = null;

		[XmlIgnore]
		public ICommand AddLevel {
			get;
		}

		[XmlIgnore]
		public ICommand RemoveLevel {
			get;
		}
		
		//[XmlIgnore]
		//public ICommand AddEntity {
		//	get;
		//	private set;
		//}
		
		public Project() {
			AddLevel = new RelayCommand<object>(x => {
				_AddLevel("NewLevel");
				var level = _Levels.Last();
				var index = _Levels.Count - 1;
				var stepName = $"Project | Add Level \"{level.Name}\".";
				StepRecorder?.Add(
					new Step(
						stepName,
						() => _RemoveLevel(level),
						() => _Levels.Insert(index, level)
					)
				);
				Logger.AddLog(LogMessageType.Info, stepName);
			});
			
			RemoveLevel = new RelayCommand<Level>(x => {
				var index = _Levels.IndexOf(x);
				_RemoveLevel(x);
				var stepName = $"Project | Remove Level \"{x.Name}\".";
				StepRecorder?.Add(
					new Step(
						stepName,
						() => _Levels.Insert(index, x),
						() => _RemoveLevel(x)
					)
				);
				Logger.AddLog(LogMessageType.Info, stepName);
			});
			
			Levels = new(_Levels);
		}
		
		public static Project? Load(string projectFilePath) {
			CurrentProject = Serializer.XmlFromFile<Project>(projectFilePath);
			return CurrentProject;
		}
		
		public void Save() {
			Serializer.XmlToFile(ProjectFilePath, this);
			Logger.AddLog(LogMessageType.Info, "Project | Save.");
		}
		
		public void UnLoad() {
			Serializer.XmlToFile(ProjectFilePath, this);
		}

		private void _AddLevel(string name) {
			Debug.Assert(StringUtils.IsStringValid(name));
			Level level = new() {
				Name = name,
			};
			_Levels.Add(level);
			CurrentLevel = level;
		}
		
		private void _RemoveLevel(Level level) {
			_Levels.Remove(level);
		}
	}
}