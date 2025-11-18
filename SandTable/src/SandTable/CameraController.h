/**
 * @file SandTable/CameraController.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief 相机控制器
 */

#ifndef SANDTABLE_CAMERACONTROLLER_H
#define SANDTABLE_CAMERACONTROLLER_H

#include <SandTable/Renderer/Camera.h>
#include <SandTable/Core/Clock.h>
#include <SandTable/Events/ApplicationEvent.h>
#include <SandTable/Events/MouseEvent.h>

namespace SandTable
{
	class CameraController
	{
	public:
		CameraController() = default;
		~CameraController() = default;

	private:
		float m_AspectRatio;
		float m_ZoomRatio;
		ObjectRef<Camera> m_Camera;
	};

	class OrthoGraphicCameraController
	{
	public:
		enum class Direction : unsigned char
		{
			Up, Down,
			Left, Right,
			Forward, Backward,
			clockwise, counterclockwise
		};
	public:
		OrthoGraphicCameraController(float aspectRatio, bool enableRotation = true, bool enableTranslatedSpeed = true);
		~OrthoGraphicCameraController() = default;

	public:
		// Getter
		const ObjectRef<OrthographicCamera>& GetCamera() const;
		const glm::vec3& GetPosition() const;
		const float GetRotation() const;
		const float GetAspectRatio() const;
		const float GetZoomRatio() const;
		const bool IsRotationAllowed() const;
		const bool IsTranslatedSpeedAllowed() const;

		// Setter
		void SetPosition(const glm::vec3& position);
		void SetRotation(const float rotation);
		void SetMoveSpeed(const float speed);
		void SetTranslatedSpeed(const float speed);
		void SetRotationSpeed(const float speed);
		void SetZoomRatio(const float zoomRatio);

		// 选项控制
		void AllowRotation(bool enabled);
		void AllowTranslatedSpeed(bool enabled);

		// 事件
		void OnUpdate(TimeStep timeStep);
		void OnEvent(Event& event);

	private:
		void Move(Direction direction, float speed, TimeStep timeStep);
		void Rotate(Direction direction, float speed, TimeStep timeStep);
		bool OnMouseScrolled(MouseScrolled& event);
		bool OnWindowResized(WindowResize& event);

	private:
		ObjectRef<OrthographicCamera> m_Camera;

		float m_AspectRatio;
		float m_ZoomRatio = 1.0f;

		bool o_Rotation;
		bool o_TranslatedSpeed;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;

		float m_CameraMoveSpeed = 1.0f;	/// 在不同缩放下的移动速度，看起来应该一样快
		float m_CameraRotationSpeed = 1.0f;
	};
}

#endif