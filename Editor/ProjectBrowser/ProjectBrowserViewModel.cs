/// @file ProjectBrowser/ProjectBrowserViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using Editor.Core;

namespace Editor.ProjectBrowser {
	public class ProjectBrowserViewModel : ViewModelBase {
		public readonly LoadProjectViewModel LoadProjectViewModel;
		public readonly NewProjectViewModel NewProjectViewModel;
		
		public ViewModelBase CurrentViewModel {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(CurrentViewModel));
				}
			}
		}
		
		public ProjectBrowserViewModel() {
			LoadProjectViewModel = new(this);
			NewProjectViewModel = new(this);
			
			CurrentViewModel = LoadProjectViewModel;
		}
	}
}