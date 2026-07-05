/// @file Console/Logger.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using Editor.Core;
using System.Collections.ObjectModel;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Data;

namespace Editor.Utility {
	[Flags]
	public enum LogMessageType {
		Info = 0x0,
		Warning = 0x1,
		Error = 0x2
	}

	public class LogMessage {
		public LogMessageType Type {
			get;
		}
		public DateTime Time {
			get;
		}
		public string Caller {
			get;
		}
		public string Message {
			get;
		}
		public int Line {
			get;
		}
		public string File {
			get;
		}
		public string Format => $"[{Time}] {File}:{Line} | {Message}";

		public LogMessage(LogMessageType type, string message, string caller, string file, int line) {
			Time = DateTime.Now;
			Type = type;
			Message = message;
			Caller = caller;
			File = file;
			Line = line;
		}
	}

	public class Logger : ViewModelBase {
		private static ObservableCollection<LogMessage> _Messages = [];
		public static ReadOnlyObservableCollection<LogMessage> Messages = new(_Messages);
		
		private static int _Filter = (int)(LogMessageType.Warning | LogMessageType.Error);
		public static CollectionViewSource FilteredMessages {
			get;
		} = new() { Source = Messages };

		public static async void AddLog(
			LogMessageType type,
			string message,
			[CallerMemberName] string caller = "",
			[CallerFilePath] string file = "",
			[CallerLineNumber] int line = 0
		) {
			await Application.Current.Dispatcher.BeginInvoke(new Action(() => _Messages.Add(new(type, message, caller, file, line))));
		}
		
		public static async void Clear() {
			await Application.Current.Dispatcher.BeginInvoke(new Action(() => _Messages.Clear()));
		}
		
		public static void SetFilter(int mask) {
			_Filter = mask;
			FilteredMessages.View.Refresh();
		}
		
		static Logger() {
			FilteredMessages.Filter += (sender, args) => {
				var type = (int)(args.Item as LogMessage).Type;
				args.Accepted = (type & _Filter) != 0;
			};
		}
	}
}