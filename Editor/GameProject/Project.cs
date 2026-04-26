/// <file> GameProject/Project.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.9 </version>
/// <date> 2026-4-26 </date>

using System.Collections.ObjectModel;
using System.Xml.Serialization;
using Editor.Core;

namespace Editor.GameProject
{
	/// <summary>
	/// 项目的信息，将来可能用xml或json存储为项目文件
	/// </summary>
	public class Project : ViewModelBase {
		public string Name {
			get;
			set;
		} = "Untitled";
		public string IconPath {
			get;
			set;
		} = string.Empty;
		private ObservableCollection<Level> _Levels = new();
		[XmlIgnore]
		public ReadOnlyObservableCollection<Level> Levels {
			get;
		}
		public Project() {
			_Levels.Add(new Level("Default Level"));
		}
		public Project(string name) {
			Name = name;
			_Levels.Add(new Level("Default Level"));
		}
	}
}
