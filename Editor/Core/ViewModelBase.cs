/// @file Core/ViewModelBase.cs
/// author LinhengXilan
/// @version 0.0.0.4
/// @date 2025-5-16

using System.ComponentModel;

namespace Editor.Core
{
    public class ViewModelBase : INotifyPropertyChanged {
	    public event PropertyChangedEventHandler? PropertyChanged;

	    protected void OnPropertyChanged(string propertyName) {
		    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
	    }
	}
}
