/// @file Editors/EditorWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.19
/// @date 2025-5-28

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

		public ICommand Undo {
			get;
		}
		
		public ICommand Redo {
			get;
		}
		
		public ICommand ConsoleButtonClicked {
			get;
		}

		public EditorWindowViewModel() {
			CurrentProject = Project.Load(Project.ProjectFilePath);
			Undo = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Undo());
			Redo = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Redo());
			ConsoleButtonClicked = new RelayCommand<object>(x => OpenConsole());
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