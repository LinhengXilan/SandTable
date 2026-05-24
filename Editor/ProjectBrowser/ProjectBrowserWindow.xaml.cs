/// @file ProjectBrowser/ProjectBrowserWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.13
/// @date 2025-5-24

using Editor.Core.WindowMessage;
using Editor.Utility;
using System.Windows;
using Windows.Devices.PointOfService;

namespace Editor.ProjectBrowser {
	
	public partial class ProjectBrowserWindow : Window {
		public ProjectBrowserWindow() {
			InitializeComponent();
			WindowUtils.Enable(this);
			Messenger.MessageReceived += OnMessage;
		}
		public void MinimizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowState = WindowState.Minimized;
		}
		
		public void MaximizationButtonClicked(object sender, RoutedEventArgs args) {
			WindowUtils.Maximize(this);
		}
		
		public void CloseButtonClicked(object sender, RoutedEventArgs args) {
			Close();
		}
		
		private void OnMessage(Message message) {
			if (message is CloseAndOpenNewWindowMessage closeAndOpenNewWindowMessage) {
				if (Activator.CreateInstance(closeAndOpenNewWindowMessage.NewWindow) is Window newWindow) {
					newWindow.Show();
					if (Application.Current.MainWindow == this) {
						Application.Current.MainWindow = newWindow;
					}
					Close();
				}
			}
		}
	}
}