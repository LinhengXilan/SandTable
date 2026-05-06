/// <file> GameProject/Project.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.12 </version>
/// <date> 2026-5-6 </date>

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
		/// <summary>
		/// 存储为绝对路径
		/// </summary>
		public string IconPath {
			get;
			set;
		} = string.Empty;
		private ObservableCollection<Level> _Levels = [];
		[XmlIgnore]
		public ReadOnlyObservableCollection<Level> Levels {
			get;
		}
		public Project() {
			Levels = new ReadOnlyObservableCollection<Level>(_Levels);
			_Levels.Add(new Level("Default Level"));
		}
		public Project(string name) {
			Name = name;
			Levels = new ReadOnlyObservableCollection<Level>(_Levels);
			_Levels.Add(new Level("Default Level"));
		}
	}
}
