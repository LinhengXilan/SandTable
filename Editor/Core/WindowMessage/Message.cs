/// @file Core/WindowMessage/Message.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

namespace Editor.Core.WindowMessage {
	public interface IMessage {

	}

	public class OpenNewWindowMessage : IMessage {
		public Type NewWindow;
		public object? Param;
		
		public OpenNewWindowMessage(Type window) {
			NewWindow = window;
		}

		public OpenNewWindowMessage(Type window, object param) {
			NewWindow = window;
			Param = param;
		}
	}
}
