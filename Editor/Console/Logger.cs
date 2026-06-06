/// @file Console/Logger.cs
/// @author LinhengXilan
/// @version 0.0.0.23
/// @date 2025-6-7

using Editor.Core;
using System.Collections.ObjectModel;

namespace Editor.Console {
	public class Logger : ViewModelBase {
		private static ObservableCollection<string> _LogContent = [];
		public static ReadOnlyObservableCollection<string> LogContent = new(_LogContent);

		public static void AddLog(string log) {
			_LogContent.Add($"[{DateTime.Now:hh:mm:ss}] " + log);
		}
	}
}