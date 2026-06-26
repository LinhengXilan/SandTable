/// @file Component/Entity.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26

using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Collections.ObjectModel;
using System.Diagnostics;

namespace Editor.Components {
	public class Entity : ViewModelBase {
		public string Name {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Name));
				}
			}
		} = string.Empty;
		
		public Level Parent {
			get;
			private set;
		}
		
		private readonly ObservableCollection<Component> _Components = [];
		
		public ReadOnlyObservableCollection<Component> Components {
			get;
		}
		
		public Entity(Level level) {
			Debug.Assert(level != null);
			Parent = level;
			Components = new(_Components);
			_Components.Add(new() {
				Name = "TComponent"
			});
		}
	}
}
