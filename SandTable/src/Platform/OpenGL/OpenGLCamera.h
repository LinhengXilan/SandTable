/**
 * @file Platform/OpenGL/OpenGLCamera.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief OpenGL相机实现头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLCAMERA_H
#define PLATFORM_OPENGL_OPENGLCAMERA_H

#include <SandTable/Renderer/Camera.h>

namespace SandTable
{
	class OpenGLOrthographicCamera : public OrthographicCamera
	{
	public:
		OpenGLOrthographicCamera() = default;
		OpenGLOrthographicCamera(float left, float right, float bottom, float top);
		~OpenGLOrthographicCamera() = default;

	public:
		void SetPosition(const glm::vec3& position) override;
		void SetRotation(const float rotation) override;
		void SetMoveSpeed(const float speed) override;
		void SetRotateSpeed(const float speed) override;

		inline const CameraType GetCameraType() const override { return CameraType::Orthographic; };
		inline const glm::vec3& GetPosition() const override { return m_Position; };
		inline const float GetRotation() const override { return m_Rotation; };
		inline const glm::mat4& GetViewMatrix() const override { return m_ViewMatrix; };
		inline const glm::mat4& GetProjectionMatrix() const override { return m_ProjectionMatrix; };
		inline const glm::mat4& GetViewProjectionMatrix() const override { return m_ViewProjectionMatrix; };

		void RecalculateViewMatrix() override;
		void Move(Direction direction) override;
		void Move(Direction direction, TimeStep timeStep) override;
		void Move(Direction direction, float speed) override;
		void Move(Direction direction, float speed, TimeStep timeStep) override;
		void Rotate(Direction direction) override;
		void Rotate(Direction direction, TimeStep timeStep) override;
		void Rotate(Direction direction, float speed) override;
		void Rotate(Direction direction, float speed, TimeStep timeStep) override;

	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position;
		float m_Rotation;
		float m_MoveSpeed;
		float m_RotateSpeed;
	};
}

#endif