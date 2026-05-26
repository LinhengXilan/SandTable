/// @file Editors/EditorWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Windows.Input;

namespace Editor.Editors {
	public class EditorWindowViewModel : ViewModelBase {
		public ICommand Undo {
			get;
		}
		
		public ICommand Redo {
			get;
		}
		
		public Project? CurrentProject {
			get;
		}
		
		public EditorWindowViewModel() {
			CurrentProject = Project.Load(Project.ProjectFilePath);
			Undo = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Undo());
			Redo = new RelayCommand<object>(x => CurrentProject?.StepRecorder.Redo());
		}
	}
}