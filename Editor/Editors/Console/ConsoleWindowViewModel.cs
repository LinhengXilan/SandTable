/// @file Console/ConsoleWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.31
/// @date 2026-7-9

using Editor.Core;
using Editor.Utility;

namespace Editor.Editors.Console {
	public class ConsoleWindowViewModel : ViewModelBase {
		

		public ConsoleWindowViewModel() {
			Logger.AddLog(LogMessageType.Error, "LogMessageType.Error");
			Logger.AddLog(LogMessageType.Warning, "LogMessageType.Warning");
			Logger.AddLog(LogMessageType.Info, "LogMessageType.Info");
		}
	}
}