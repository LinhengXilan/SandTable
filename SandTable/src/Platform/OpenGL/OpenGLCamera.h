/**
 * @file Platform/OpenGL/OpenGLCamera.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief OpenGL相机
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
		OpenGLOrthographicCamera(float aspectRatio, float zoomRatio);
		~OpenGLOrthographicCamera() override = default;

	public:
		Camera::CameraType GetCameraType() const override;
		const glm::mat4& GetViewMatrix() const override;
		const glm::mat4& GetProjectionMatrix() const override;
		const glm::mat4& GetViewProjectionMatrix() const override;

		void SetProjectionMatrix(float left, float right, float bottom, float top) override;
		void SetProjectionMatrix(float aspectRatio, float zoomRatio) override;

		void RecalculateViewMatrix(const glm::vec3& position, float rotation) override;

	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewProjectionMatrix;
	};
}

#endif