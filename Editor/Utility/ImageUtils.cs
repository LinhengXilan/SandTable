

using System.IO;
using System.Windows.Media.Imaging;

namespace Editor.Utility
{
    public class ImageUtils
    {
	    public static byte[]? LoadIcon(string path, int size) {
		    if (!File.Exists(path)) {
			    return null;
		    }

		    using FileStream stream = new(path, FileMode.Open, FileAccess.Read);
		    var decoder = BitmapDecoder.Create(stream, BitmapCreateOptions.None, BitmapCacheOption.None);

		    var targetFrame = decoder.Frames.FirstOrDefault(frame => frame.PixelWidth == size && frame.PixelHeight == size);
		    if (targetFrame == null) {
			    return null;
		    }

			BmpBitmapEncoder encoder = new();
		    encoder.Frames.Add(targetFrame);
		    using MemoryStream ms = new();
		    encoder.Save(ms);
		    return ms.ToArray();
	    }
    }
}
