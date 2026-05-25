/// @file Core/WindowMessage/Message.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

namespace Editor.Core.WindowMessage {
	public interface IMessage {

	}

	public class OpenNewWindowMessage : IMessage {
		public Type NewWindow;
		public object? Param;
		
		public OpenNewWindowMessage(Type window, object? param) {
			NewWindow = window;
			Param = param;
		}
	}
}
