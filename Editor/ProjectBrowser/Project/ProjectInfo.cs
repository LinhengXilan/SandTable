/// @file ProjectBrowser/ProjectInfo.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using Editor.Core;

namespace Editor.ProjectBrowser.Project {
	public class ProjectInfo : ViewModelBase {
		public string Name {
			get;
			set;
		} = string.Empty;
		
		public string IconPath {
			get;
			set;
		} = string.Empty;
		
		public string Path {
			get;
			set;
		} = string.Empty;
		
		public DateTime LastModifyTime {
			get;
			set;
		} = DateTime.Now;
	}
}