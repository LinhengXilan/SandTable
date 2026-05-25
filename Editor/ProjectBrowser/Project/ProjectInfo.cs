/// @file ProjectBrowser/ProjectInfo.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

using Editor.Core;
using System.Xml.Serialization;

namespace Editor.ProjectBrowser.Project {
	public class ProjectInfo : ViewModelBase {
		public string Name {
			get;
			set;
		} = string.Empty;
		
		/// <summary>
		/// 项目文件的路径
		/// </summary>
		public string Path {
			get;
			set;
		} = string.Empty;

		[XmlIgnore]
		public byte[]? Icon {
			get;
			set;
		} = null;
		
		public DateTime LastModifyTime {
			get;
			set;
		} = DateTime.Now;
	}
}