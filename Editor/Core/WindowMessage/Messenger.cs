/// @file Core/WindowMessage/Messenger.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

namespace Editor.Core.WindowMessage {
	public class Messenger {
		public static event Action<IMessage>? MessageReceived;
		public static void Send(IMessage message) => MessageReceived?.Invoke(message);
	}
}