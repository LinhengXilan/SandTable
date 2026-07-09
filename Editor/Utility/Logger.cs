/// @file Console/Logger.cs
/// @author LinhengXilan
/// @version 0.0.0.29
/// @date 2026-7-8

using Editor.Core;
using System.Collections.ObjectModel;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Data;

namespace Editor.Utility {
	[Flags]
	public enum LogMessageType {
		Info = 0x1,
		Warning = 0x2,
		Error = 0x4
	}

	public class LogMessage (LogMessageType type, string message, string caller, string file, int line) {
		public LogMessageType Type {
			get;
		} = type;
		public DateTime Time {
			get;
		} = DateTime.Now;
		public string Caller {
			get;
		} = caller;
		public string Message {
			get;
		} = message;
		public int Line {
			get;
		} = line;
		public string File {
			get;
		} = file;
		

		public string Format => $"[{Time}] {File}:{Line} | {Message}";
	}

	public class Logger : ViewModelBase {
		private static readonly ObservableCollection<LogMessage> _Messages = [];
		public static readonly ReadOnlyObservableCollection<LogMessage> Messages = new(_Messages);
		private static LogMessageType _Filter = LogMessageType.Warning | LogMessageType.Error | LogMessageType.Info;


		public static CollectionViewSource FilteredMessages {
			get;
		} = new() { Source = Messages };
		
		public static async void AddLog(LogMessageType type, string message, [CallerMemberName] string caller = "", [CallerFilePath] string file = "", [CallerLineNumber] int line = 0) {
			await Application.Current.Dispatcher.BeginInvoke(new Action(() => _Messages.Add(new(type, message, caller, file, line))));
		}

		public static async void Clear() {
			await Application.Current.Dispatcher.BeginInvoke(new Action(() => _Messages.Clear()));
		}
		
		public static void SetFilter(LogMessageType mask) {
			_Filter = mask;
			FilteredMessages.View.Refresh();
		}
		
		static Logger() {
			FilteredMessages.View.Filter = obj => {
				if (obj is LogMessage message) {
					return (message.Type & _Filter) != 0;
				}
				return false;
			};
		}
	}
}