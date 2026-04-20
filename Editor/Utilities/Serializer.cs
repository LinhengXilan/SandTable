/// <file> Utilities/Serializer.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.5 </version>
/// <date> 2026-4-20 </date>

using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;

namespace Editor.Utilities {
	public static class Serializer {
		public static void ToFile<T>(T instance, string path) {
			try {
				using var fs = new FileStream(path, FileMode.Create);
				var serializer = new DataContractSerializer(typeof(T));
				serializer.WriteObject(fs, instance);
			}
			catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
		public static T FromFile<T>(string path) {
			try {
				using var fs = new FileStream(path, FileMode.Open);
				var serializer = new DataContractSerializer(typeof(T));
				return (T)serializer.ReadObject(fs);
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
				return default(T);
			}
		}
	}
}