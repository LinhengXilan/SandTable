/// @file ProjectBrowser/ProjectBrowserWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using Editor.Core.WindowMessage;
using Editor.Utility;
using System.Windows;
using System.Windows.Media;

namespace Editor.ProjectBrowser {
	
	public partial class ProjectBrowserWindow : Window {
		public ProjectBrowserWindow() {
			InitializeComponent();
			WindowUtils.Enable(this, WindowUtils.Option.Clip);
			Messenger.MessageReceived += OnMessage;
			Loaded += OnLoaded;
		}
		
		private void OnLoaded(object sender, RoutedEventArgs args) {
			var rectangleGeometry = new RectangleGeometry(new Rect(0, 0, ActualWidth, ActualHeight), 6, 6);
			Clip = rectangleGeometry;
			SizeChanged += (sender, args) => {
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

		private void OnMessage(IMessage message) {
			if (message is OpenNewWindowMessage openNewWindowMessage) {
				if (Activator.CreateInstance(openNewWindowMessage.NewWindow) is Window editor) {
					editor.Show();
					if (Application.Current.MainWindow == this) {
						Application.Current.MainWindow = editor;
					}
					Close();
				}
			}
		}
	}
}