/// @file Utility/StepRecorder.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using System.Collections.ObjectModel;
using System.Diagnostics;

namespace Editor.Utility {
	public interface IStep {
		string Name {
			get;
		}
		
		void Undo();
		void Redo();
	}
	
	public class Step : IStep {
		private readonly Action? _UndoAction;
		private readonly Action? _RedoAction;
		
		public string Name {
			get;
		}
		
		public void Undo() => _UndoAction?.Invoke();
		public void Redo() => _RedoAction?.Invoke();
		
		public Step(string name) {
			Name = name;
			_UndoAction = null;
			_RedoAction = null;
		}
		
		public Step(string name, Action undoAction, Action redoAction) : this(name) {
			Debug.Assert(undoAction != null && redoAction != null);
			_UndoAction = undoAction;
			_RedoAction = redoAction;
		}
	}

	public class StepRecorder {
		private readonly ObservableCollection<IStep> _RedoSteps = [];
		private readonly ObservableCollection<IStep> _UndoSteps = [];
		
		public ReadOnlyObservableCollection<IStep> RedoSteps {
			get;
		}
		
		public ReadOnlyObservableCollection<IStep> UndoSteps {
			get;
		}
		
		public StepRecorder() {
			RedoSteps = new(_RedoSteps);
			UndoSteps = new(_UndoSteps);
		}
		
		public void Add(IStep step) {
			_UndoSteps.Add(step);
		}
		
		public void Reset() {
			_RedoSteps.Clear();
			_UndoSteps.Clear();
		}
		
		public void Undo() {
			if (_UndoSteps.Any()) {
				var step = _UndoSteps.Last();
				Logger.AddLog(LogMessageType.Info, $"Undo | {step.Name}");
				_UndoSteps.RemoveAt(_UndoSteps.Count - 1);
				step.Undo();
				_RedoSteps.Add(step);
			}
		}
		
		public void Redo() {
			if (_RedoSteps.Any()) {
				var step = _RedoSteps.Last();
				Logger.AddLog(LogMessageType.Info, $"Redo | {step.Name}");
				_RedoSteps.RemoveAt(_RedoSteps.Count - 1);
				step.Redo();
				_UndoSteps.Add(step);
			}
		}
	}
}