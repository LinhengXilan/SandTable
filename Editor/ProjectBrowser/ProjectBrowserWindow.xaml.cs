/// @file ProjectBrowser/ProjectBrowserWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.14
/// @date 2025-5-25

using Editor.Core.WindowMessage;
using Editor.Utility;
using System.Windows;
using System.Windows.Media;

namespace Editor.ProjectBrowser {
	
	public partial class ProjectBrowserWindow : Window {
		public ProjectBrowserWindow() {
			InitializeComponent();
			WindowUtils.Enable(this);
			Messenger.MessageReceived += OnMessage;
			Loaded += OnLoaded;
		}
		
		private void OnLoaded(object sender, RoutedEventArgs args) {
			var rectangleGeometry = new RectangleGeometry(new Rect(0, 0, ActualWidth, ActualHeight), 6, 6);
			Clip = rectangleGeometry;
			this.SizeChanged += (sender, args) => {
				rectangleGeometry.Rect = new Rect(0, 0, ActualWidth, ActualHeight);
			};
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