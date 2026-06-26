/// @file Editors/MainEditor/MainEditorWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26

using Editor.Console;
using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Windows;
using System.Windows.Input;

namespace Editor.Editors.MainEditor {
	public class MainEditorWindowViewModel : ViewModelBase {
		public Project? CurrentProject {
			get;
		} = null;

		private Window? _ConsoleWindow;
		
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

		public MainEditorWindowViewModel() {
			CurrentProject = Project.Load(Project.ProjectFilePath);
			if (CurrentProject != null) {
				NewLevelButtonCommand = CurrentProject.AddLevel;
			}

			UndoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder?.Undo());
			RedoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder?.Redo());
			SaveCommand = new RelayCommand<object>(x => CurrentProject?.Save());
			ConsoleButtonClicked = new RelayCommand<object>(x => OpenConsole());
		}
		
		private void OpenConsole() {
			if (_ConsoleWindow == null) {
				_ConsoleWindow = new ConsoleWindow();
				_ConsoleWindow.Show();
			} else {
				_ConsoleWindow.Close();
				_ConsoleWindow = null;
			}
		}
	}
}