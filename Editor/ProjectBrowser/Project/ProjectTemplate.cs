/// @file ProjectBrowser/ProjectTemplate.cs
/// author LinhengXilan
/// @version 0.0.0.7
/// @date 2025-5-20

using Editor.Core;

namespace Editor.ProjectBrowser.Project {
	public class ProjectTemplate : ViewModelBase {
		public string Type {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Type));
				}
			}
		} = string.Empty;
		
		public string Description {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Description));
				}
			}
		} = string.Empty;
	}
}