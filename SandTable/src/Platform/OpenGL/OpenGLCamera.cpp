/**
 * @file Platform/OpenGL/OpenGLCamera.cpp
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief OpenGL相机实现
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLCamera.h>
#include <glm/gtc/matrix_transform.hpp>
#include <SandTable/Input.h>
#include <SandTable/KeyCode.h>
#include <SandTable/Log.h>

namespace SandTable
{
	OpenGLOrthographicCamera::OpenGLOrthographicCamera(float left, float right, float bottom, float top)
		: m_Position(0.0f), m_ProjectionMatrix(glm::ortho(left, right, bottom, top)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OpenGLOrthographicCamera::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::SetRotation(const float& rotation)
	{
		m_Rotation = rotation;
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position)
							* glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));
		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OpenGLOrthographicCamera::OnUpdate()
	{
		if (Input::IsKeyPressed(KEY_W))
		{
			m_Position.y += 0.01f;
			SANDTABLE_CORE_INFO("KEY_W");
		}
		if (Input::IsKeyPressed(KEY_S))
		{
			m_Position.y -= 0.01f;
			SANDTABLE_CORE_INFO("KEY_S");
		}
		if (Input::IsKeyPressed(KEY_A))
		{
			m_Position.x -= 0.01f;
			SANDTABLE_CORE_INFO("KEY_A");
		}
		if (Input::IsKeyPressed(KEY_D))
		{
			m_Position.x += 0.01f;
			SANDTABLE_CORE_INFO("KEY_D");
		}
		RecalculateViewMatrix();
	}
}