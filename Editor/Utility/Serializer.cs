/// @file Utility/Serializer.cs
/// author LinhengXilan
/// @version 0.0.0.7
/// @date 2025-5-20

using System.Diagnostics;
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace Editor.Utility
{
	public class Serializer
	{
		public static void XmlToFile<T>(string file, T instance) {
			try {
				FileStream fs = File.Exists(file) ? new FileStream(file, FileMode.Open) : new FileStream(file, FileMode.Create);
				XmlSerializer serializer = new (typeof(T));
				XmlWriterSettings setting = new() {
					Encoding = Encoding.UTF8,
					Indent = true,
					IndentChars = "\t"
				};
				
				XmlWriter writer = XmlWriter.Create(fs, setting);
				XmlSerializerNamespaces namespaces = new ();
				namespaces.Add(string.Empty, string.Empty);
				serializer.Serialize(writer, instance, namespaces);
				fs.Close();
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}
		
		public static void XmlToFile<T>(string file, T instance, string nameSpacePrefix, string nameSpace) {
			try {
				using FileStream fs = File.Exists(file) ? new FileStream(file, FileMode.Open) : new FileStream(file, FileMode.Create);
				XmlSerializer serializer = new (typeof(T));
				XmlWriterSettings setting = new() {
					Encoding = Encoding.UTF8,
					Indent = true,
					IndentChars = "\t"
				};
				
				XmlWriter writer = XmlWriter.Create(fs, setting);
				XmlSerializerNamespaces namespaces = new XmlSerializerNamespaces();
				namespaces.Add(nameSpacePrefix, nameSpace);
				serializer.Serialize(writer, instance, namespaces);
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
			}
		}

		public static T? XmlFromFile<T>(string file) {
			try {
				using FileStream fs = new (file, FileMode.Open);
				XmlSerializer serializer = new (typeof(T));
				return (T?)serializer.Deserialize(fs);
			} catch (Exception e) {
				Debug.WriteLine(e.Message);
				return default;
			}
		}
	}
}
