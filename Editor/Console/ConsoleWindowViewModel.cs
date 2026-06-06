/// @file Console/ConsoleWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.23
/// @date 2025-6-7

using Editor.Core;
using System.Collections.ObjectModel;

namespace Editor.Console {
	public class ConsoleWindowViewModel : ViewModelBase {
		public ReadOnlyObservableCollection<string> LogContent => Logger.LogContent;

		public ConsoleWindowViewModel() {
			
		}
	}
}