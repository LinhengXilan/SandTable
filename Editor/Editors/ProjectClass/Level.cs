/// @file Editors/ProjectClass/Level.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26

using Editor.Components;
using Editor.Core;
using System.Collections.ObjectModel;
using System.Windows.Input;

namespace Editor.Editors.ProjectClass {
    public class Level : ViewModelBase {
	    public string Name {
		    get;
		    set {
			    if (field != value) {
				    field = value;
					OnPropertyChanged(nameof(Name));
			    }
		    }
	    } = string.Empty;
	    
	    private readonly ObservableCollection<Entity> _Entities = [];
	    public ReadOnlyObservableCollection<Entity> Entities {
		    get;
	    }
	    
	    public ICommand AddEntity {
		    get;
		    private set;
	    }
	    
	    public Level() {
		    Entities = new(_Entities);
		    AddEntity = new RelayCommand<object>(x => _AddEntity("NewEntity"));
			_Entities.Add(new(this) {
				Name = "TEntity"
			});
	    }
	    
	    private void _AddEntity(string name) {
			_Entities.Add(
				new(this) {
					Name = name
				}
			);
	    }
    }
}
