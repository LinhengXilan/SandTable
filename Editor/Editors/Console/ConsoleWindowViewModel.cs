/// @file Console/ConsoleWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using Editor.Core;
using Editor.Utility;
using System.Collections.ObjectModel;

namespace Editor.Editors.Console {
	public class ConsoleWindowViewModel : ViewModelBase {
		public ReadOnlyObservableCollection<LogMessage> LogMessage => Logger.Messages;

		public ConsoleWindowViewModel() {
			
		}
	}
}