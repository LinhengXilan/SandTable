/// @file Editors/EditorWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.24
/// @date 2025-6-9

using Editor.Console;
using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Windows;
using System.Windows.Input;

namespace Editor.Editors {
	public class EditorWindowViewModel : ViewModelBase {
		public Project? CurrentProject {
			get;
		}
		
		public Window? ConsoleWindow;
		
		public ICommand NewLevelButtonCommand {
			get;
		}

		public ICommand UndoCommand {
			get;
		}
		
		public ICommand RedoCommand {
			get;
		}
		
		public ICommand SaveCommand {
			get;
		}
		
		public ICommand ConsoleButtonClicked {
			get;
		}

		public EditorWindowViewModel() {
			CurrentProject = Project.Load(Project.ProjectFilePath);
			UndoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Undo());
			RedoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Redo());
			SaveCommand = new RelayCommand<object>(x => CurrentProject?.Save());
			ConsoleButtonClicked = new RelayCommand<object>(x => OpenConsole());
			NewLevelButtonCommand = CurrentProject.AddLevel;
		}
		
		private void OpenConsole() {
			if (ConsoleWindow == null) {
				ConsoleWindow = new ConsoleWindow();
				ConsoleWindow.Show();
			} else {
				ConsoleWindow.Close();
				ConsoleWindow = null;
			}
		}
	}
}