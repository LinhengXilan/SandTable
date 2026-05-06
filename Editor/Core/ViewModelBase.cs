/// <file> Core/ViewModelBase.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.12 </version>
/// <date> 2026-5-6 </date>

using System.ComponentModel;

namespace Editor.Core {
	public class ViewModelBase : INotifyPropertyChanged {
		public event PropertyChangedEventHandler? PropertyChanged;
		protected void OnPropertyChanged(string propertyName) {
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}
	}
}