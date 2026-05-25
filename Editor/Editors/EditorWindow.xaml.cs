/// @file EditorWindow.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.17
/// @date 2025-5-26

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
			var rectangleGeometry = new RectangleGeometry(new(0, 0, ActualWidth, ActualHeight), 6, 6);
			Clip = rectangleGeometry;
			SizeChanged += (sender, args) => {
				rectangleGeometry.Rect = new(0, 0, ActualWidth, ActualHeight);
			};
			if (DataContext is not string projectFilePath) {
				return;
			}
			Project.Project.Load(projectFilePath);
			
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
