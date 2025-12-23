/**
 * @file Platform/OpenGL/OpenGLCamera.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief OpenGL相机
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLCamera.h>
#include <glm/gtc/matrix_transform.hpp>
#include <SandTable/Debug/Instrumentor.h>

namespace SandTable
{
	OpenGLOrthographicCamera::OpenGLOrthographicCamera(float left, float right, float bottom, float top)
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	OpenGLOrthographicCamera::OpenGLOrthographicCamera(float aspectRatio, float zoomRatio)
		: OpenGLOrthographicCamera(-aspectRatio * zoomRatio, aspectRatio * zoomRatio, -zoomRatio, zoomRatio)
	{
		
	}

	Camera::CameraType OpenGLOrthographicCamera::GetCameraType() const
	{
		return CameraType::Orthographic;
	};

	const glm::mat4& OpenGLOrthographicCamera::GetViewMatrix() const
	{
		return m_ViewMatrix;
	};

	const glm::mat4& OpenGLOrthographicCamera::GetProjectionMatrix() const
	{
		return m_ProjectionMatrix;
	};

	const glm::mat4& OpenGLOrthographicCamera::GetViewProjectionMatrix() const
	{
		return m_ViewProjectionMatrix;
	};

	void OpenGLOrthographicCamera::SetProjectionMatrix(float left, float right, float bottom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OpenGLOrthographicCamera::SetProjectionMatrix(float aspectRatio, float zoomRatio)
	{
		m_ProjectionMatrix = glm::ortho(-aspectRatio * zoomRatio, aspectRatio * zoomRatio, -zoomRatio, zoomRatio, -1.0f, 1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OpenGLOrthographicCamera::RecalculateViewMatrix(const glm::vec3& position, float rotation)
	{
		SANDTABLE_PROFILE_FUNCTION();
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
							* glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}