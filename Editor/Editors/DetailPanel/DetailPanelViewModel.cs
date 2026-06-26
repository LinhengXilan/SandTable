/// @file Editors/DetailPanel/DetailPanelViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26

using Editor.Components;
using Editor.Core;
using Editor.Editors.ProjectClass;
using System.Collections.ObjectModel;
using System.ComponentModel;

namespace Editor.Editors.DetailPanel {
	public class DetailPanelViewModel : ViewModelBase {
		public ReadOnlyObservableCollection<Entity>? Entities {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Entities));
				}
			}
		} = null;
		
		public DetailPanelViewModel() {
			Project.CurrentProject?.PropertyChanged += OnCurrentLevelChanged;
		}
		
		private void OnCurrentLevelChanged(object? sender, PropertyChangedEventArgs args) {
			if (args.PropertyName == nameof(Project.CurrentLevel)) {
				Entities = Project.CurrentProject?.CurrentLevel?.Entities;
			}
		}
	}
}
