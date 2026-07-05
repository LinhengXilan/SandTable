/// @file Editors/MainEditor/MainEditorWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using Editor.Editors.Console;
using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Windows;
using System.Windows.Input;

namespace Editor.Editors.MainEditor {
	public class MainEditorWindowViewModel : ViewModelBase {
		public Project? CurrentProject {
			get;
		}
		
		private Window? _ConsoleWindow;
		
		public ICommand NewLevelButtonCommand {
			get;
		} = new RelayCommand<object>(x =>  {});
	
		public ICommand UndoCommand {
			get;
		} = new RelayCommand<object>(x => { });

		public ICommand RedoCommand {
			get;
		} = new RelayCommand<object>(x => { });

		public ICommand SaveCommand {
			get;
		} = new RelayCommand<object>(x => { });

		public ICommand ConsoleButtonClicked {
			get;
		} = new RelayCommand<object>(x => { });

		public MainEditorWindowViewModel() {
			CurrentProject = Project.Load(Project.ProjectFilePath);
			if (CurrentProject == null) {
				return;
			}
			NewLevelButtonCommand = CurrentProject.AddLevel;

			UndoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Undo());
			RedoCommand = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Redo());
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