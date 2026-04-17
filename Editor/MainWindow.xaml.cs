/// <file> MainWindow.xaml.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.2 </version>
/// <date> 2026-4-17 </date>

using System.Windows;
using Editor.GameProject;

namespace Editor {
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window {
        public MainWindow() {
            InitializeComponent();
            Loaded += OnMainWindowLoaded;
        }

        private void OnMainWindowLoaded(object sender, RoutedEventArgs e) {
            Loaded -= OnMainWindowLoaded;
            OpenProjectBrowserDialog();
        }

        private void OpenProjectBrowserDialog() {
            var projectBrowser = new ProjectBrowserDialog();
            if (projectBrowser.ShowDialog() == false) {
                Application.Current.Shutdown();
            } else {

            }
        }
    }
}