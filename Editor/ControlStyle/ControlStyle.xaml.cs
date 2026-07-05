/// @file ControlStyle/ControlStyle.xaml.cs
/// @author LinhengXilan
/// @version 0.0.0.28
/// @date 2026-7-5

using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Editor.ControlStyle {
    public partial class ControlStyle : ResourceDictionary {
	    private void TextBoxKeyDown(object sender, KeyEventArgs args) {
		    var textBox = sender as TextBox;
		    var expression = textBox.GetBindingExpression(TextBox.TextProperty);
		    if (expression == null) {
			    return;
		    }
		    if (args.Key == Key.Enter) {

		    } else if (args.Key == Key.Escape) {

		    }
	    }
	}
}