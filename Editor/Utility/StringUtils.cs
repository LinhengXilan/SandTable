/// @file Utility/StringUtils.cs
/// @author LinhengXilan
/// @version 0.0.0.18
/// @date 2025-5-27

using System.IO;

namespace Editor.Utility {
	public class StringUtils {
		public static bool IsStringValid(string str) {
			bool result = true;

			result |= string.IsNullOrEmpty(str.Trim());
			result |= string.IsNullOrWhiteSpace(str.Trim());
			result |= str.IndexOfAny(Path.GetInvalidFileNameChars()) != -1;
			result |= string.IsNullOrEmpty(str.Trim());
			result |= str.IndexOfAny(Path.GetInvalidPathChars()) != -1;
			result |= Directory.Exists(str) && Directory.EnumerateFileSystemEntries(str).Any();
			
			return result;
		}
	}
}
