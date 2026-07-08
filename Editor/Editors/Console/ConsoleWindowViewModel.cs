/// @file Console/ConsoleWindowViewModel.cs
/// @author LinhengXilan
/// @version 0.0.0.29
/// @date 2026-7-8

using Editor.Core;
using Editor.Utility;
using System.ComponentModel;

namespace Editor.Editors.Console {
	public class ConsoleWindowViewModel : ViewModelBase {
		public static ICollectionView MessageView => Logger.FilteredMessages.View;
		
		public ConsoleWindowViewModel() {

		}
	}
}