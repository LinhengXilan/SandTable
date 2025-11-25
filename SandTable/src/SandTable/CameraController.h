/**
 * @file SandTable/CameraController.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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
		float GetRotation() const;
		float GetAspectRatio() const;
		float GetZoomRatio() const;
		bool IsRotationAllowed() const;
		bool IsTranslatedSpeedAllowed() const;

		// Setter
		void SetPosition(const glm::vec3& position);
		void SetRotation(float rotation);
		void SetMoveSpeed(float speed);
		void SetTranslatedSpeed(float speed);
		void SetRotationSpeed(float speed);
		void SetZoomRatio(float zoomRatio);

		// 选项控制
		void AllowRotation(bool enabled);
		void AllowTranslatedSpeed(bool enabled);

		// 事件
		void OnUpdate(const TimeStep& timeStep);
		void OnEvent(Event& event);

	private:
		void Move(Direction direction, float speed, const TimeStep& timeStep);
		void Rotate(Direction direction, float speed, const TimeStep& timeStep);
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

		float m_CameraMoveSpeed = 1.0f;
		float m_CameraRotationSpeed = 1.0f;
	};
}

#endif