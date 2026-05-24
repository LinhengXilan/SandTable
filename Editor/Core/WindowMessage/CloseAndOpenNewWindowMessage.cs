/// @file Core/WindowMessage/CloseAndOpenNewWindowMessage.cs
/// @author LinhengXilan
/// @version 0.0.0.13
/// @date 2025-5-24

namespace Editor.Core.WindowMessage {
	public class CloseAndOpenNewWindowMessage (Type newWindow) : Message {
		public Type NewWindow = newWindow;
	}
}
