/// @file EditorWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.15
/// @date 2025-5-25

using Editor.Utility;
using System.Windows;
using System.Windows.Media;

namespace Editor.Editors {
	public partial class EditorWindow : Window {
		public EditorWindow() {
			InitializeComponent();
			WindowUtils.Enable(this);
			Loaded += OnLoaded;
		}
		
		private void OnLoaded(object sender, RoutedEventArgs args) {
			var rectangleGeometry = new RectangleGeometry(new Rect(0, 0, ActualWidth, ActualHeight), 6, 6);
			Clip = rectangleGeometry;
			SizeChanged += (sender, args) =>
			{
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
	}
}
