/// <file> Core/ViewModelBase.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.5 </version>
/// <date> 2026-4-20 </date>
/// 

using System.ComponentModel;

namespace Editor.Core {
	public class ViewModelBase : INotifyPropertyChanged {
		public event PropertyChangedEventHandler PropertyChanged;

		protected void OnPropertyChanged(string propertyName) {
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}
	}
}