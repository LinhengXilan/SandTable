/// @file Core/RelayCommand.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

using System.Windows.Input;

namespace Editor.Core {
	public class RelayCommand<T> : ICommand {
		private readonly Action<T> _Execute;
		private readonly Predicate<T>? _CanExecute;
		
		public bool CanExecute(object? parameter) {
			return parameter == null ? _CanExecute?.Invoke(default!) ?? true : _CanExecute?.Invoke((T)parameter) ?? true;
		}
		
		public void Execute(object? parameter) {
			if (parameter == null) {
				_Execute(default!);
			} else {
				_Execute((T)parameter);
			}
		} 
		
		public event EventHandler? CanExecuteChanged {
			add => CommandManager.RequerySuggested += value;
			remove => CommandManager.RequerySuggested -= value;
		}

		public RelayCommand(Action<T> execute, Predicate<T>? canExecute = null) {
			_Execute = execute ?? throw new ArgumentNullException(nameof(execute));
			_CanExecute = canExecute;
		}
	}
}
