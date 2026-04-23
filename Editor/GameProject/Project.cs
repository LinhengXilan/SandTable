/// <file> GameProject/Project.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.7 </version>
/// <date> 2026-4-23 </date>

using System.Collections.ObjectModel;
using Editor.Core;

namespace Editor.GameProject
{
	/// <summary>
	/// 项目的信息，将来可能用xml或json存储为项目文件
	/// </summary>
	class Project : ViewModelBase
	{
		public string Name {
			get;
			set;
		}
		private ObservableCollection<Level> _Levels = new();
		public ReadOnlyObservableCollection<Level> Levels {
			get;
		}
		
		public Project(string name) {
			Name = name;
			_Levels.Add(new Level( "Default Level"));
		}
	}
}
