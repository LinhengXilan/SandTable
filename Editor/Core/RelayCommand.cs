/// @file Core/RelayCommand.cs
/// @author LinhengXilan
/// @version 0.0.0.9
/// @date 2025-5-23

using System.Windows.Input;

namespace Editor.Core {
	public class RelayCommand (Action execute, Func<bool>? canExecute = null) : ICommand {
		private readonly Action _Execute = execute ?? throw new ArgumentNullException(nameof(execute));
		
		public bool CanExecute(object? parameter) => canExecute?.Invoke() ?? true;

		public void Execute(object? parameter) => _Execute();
		
		public event EventHandler? CanExecuteChanged;
		
		public void RaiseCanExecuteChanged() {
			CanExecuteChanged?.Invoke(this, EventArgs.Empty);
		}
	}
}
