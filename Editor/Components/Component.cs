/// @file Component/Component.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26

using Editor.Core;

namespace Editor.Components {
	public class Component : ViewModelBase {
		public string Name {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Name));
				}
			}
		} = string.Empty;
	}
}
