/// @file Utility/FileUtils.cs
/// @auther LinhengXilan
/// @version 0.0.0.22
/// @date 2025-6-3

using System.IO;

namespace Editor.Utility {
	public class FileUtils {
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
				File.Copy(file, newPath);
			}
			
			var directories = Directory.GetDirectories(sourceFolder);
			foreach (var directory in directories) {
				var dirName = Path.GetFileName(directory);
				var newDirPath = Path.Combine(destFolder, dirName);
				CopyFolder(directory, newDirPath);
			}
		}
		
		public static void AppendToFile(string filePath, string content) {

		}
	}
}