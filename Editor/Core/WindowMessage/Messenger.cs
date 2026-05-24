/// @file Core/WindowMessage/Messenger.cs
/// @author LinhengXilan
/// @version 0.0.0.13
/// @date 2025-5-24

namespace Editor.Core.WindowMessage {
	public class Messenger {
		public static event Action<Message> MessageReceived;
		public static void Send(Message message) => MessageReceived?.Invoke(message);
	}
}
