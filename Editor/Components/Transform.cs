/// @file Components/Transform.cs
/// @author LinhengXilan
/// @version 0.0.0.26
/// @date 2025-6-26
/// @brief 测试Component

using System.Numerics;

namespace Editor.Components {
	public class Transform : Component {
		public Vector3 Position {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Position));
				}
			}
		}
		
		public Vector3 Rotation {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Rotation));
				}
			}
		}
		
		public Vector3 Scale {
			get;
			set {
				if (field != value) {
					field = value;
					OnPropertyChanged(nameof(Scale));
				}
			}
		}

		public Transform() {
			
		}
	}
}
