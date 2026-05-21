/// @file Utility/File.cs
/// @auther LinhengXilan
/// @version 0.0.0.8
/// @date 2025-5-22

using System.IO;

namespace Editor.Utility {
	public class File {
		public static void CopyFolder(string sourceFolder, string destFolder) {
			if (!Directory.Exists(sourceFolder)) {
				return;
			}

			if (!Directory.Exists(destFolder)) {
				Directory.CreateDirectory(destFolder);
			}
			
			var files = Directory.GetFiles(sourceFolder);
			foreach (var file in files) {
				var fileInfo = new FileInfo(file);
				var newPath = Path.Combine(destFolder, fileInfo.Name);
				System.IO.File.Copy(file, newPath);
			}
			
			var directories = Directory.GetDirectories(sourceFolder);
			foreach (var directory in directories) {
				var dirName = Path.GetFileName(directory);
				var newDirPath = Path.Combine(destFolder, dirName);
				CopyFolder(directory, newDirPath);
			}
		}
	}
}