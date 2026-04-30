/// <file> Utilities/Serializer.cs </file>
/// <author> LinhengXilan </author>
/// <version> 0.0.0.10 </version>
/// <date> 2026-5-1 </date>

using System.Diagnostics;
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace Editor.Utilities {
	public static class Serializer {
		public static void XmlToFile<T>(T instance, string path) {
			try {
				FileStream fs;
				fs = File.Exists(path) ? new FileStream(path, FileMode.Open) : new FileStream(path, FileMode.Create);
				var serializer = new XmlSerializer(typeof(T));
				var setting = new XmlWriterSettings {
					Encoding = Encoding.UTF8,
					Indent = true,
					IndentChars = "\t"
				};
				
				var writer = XmlWriter.Create(fs, setting);
				var namespaces = new XmlSerializerNamespaces();
				namespaces.Add(string.Empty, string.Empty);
				serializer.Serialize(writer, instance, namespaces);
				fs.Close();
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
		public static void XmlToFile<T>(T instance, string path, string nameSpacePrefix, string nameSpace) {
			try {
				FileStream fs;
				fs = File.Exists(path) ? new FileStream(path, FileMode.Open) : new FileStream(path, FileMode.Create);
				var serializer = new XmlSerializer(typeof(T));
				var setting = new XmlWriterSettings {
					Encoding = Encoding.UTF8,
					Indent = true,
					IndentChars = "\t"
				};
				
				var writer = XmlWriter.Create(fs, setting);
				var namespaces = new XmlSerializerNamespaces();
				namespaces.Add(nameSpacePrefix, nameSpace);
				serializer.Serialize(writer, instance, namespaces);
				fs.Close();
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
		public static T XmlFromFile<T>(string path) {
			try {
				var fs = new FileStream(path, FileMode.Open);
				var serializer = new XmlSerializer(typeof(T));
				return (T)serializer.Deserialize(fs);
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
				return default;
			}
		}
	}
}