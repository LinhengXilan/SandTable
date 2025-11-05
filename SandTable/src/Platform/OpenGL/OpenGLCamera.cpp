/**
 * @file Platform/OpenGL/OpenGLCamera.cpp
 * @author LinhengXilan
 * @date 2025-11-5
 * @version build24
 * 
 * @brief OpenGL相机实现
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLCamera.h>
#include <glm/gtc/matrix_transform.hpp>

namespace SandTable
{
	OpenGLOrthographicCamera::OpenGLOrthographicCamera(float left, float right, float bottom, float top)
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top)), m_ViewMatrix(1.0f),
		  m_Position(0.0f), m_Rotation(0.0f),
		  m_MoveSpeed(1.0f), m_RotateSpeed(1.0f)
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

	void OpenGLOrthographicCamera::SetMoveSpeed(const float& speed)
	{
		m_MoveSpeed = speed;
	}

	void OpenGLOrthographicCamera::SetRotateSpeed(const float& speed)
	{
		m_RotateSpeed = speed;
	}

	void OpenGLOrthographicCamera::Move(Direction direction)
	{
		switch (direction)
		{
		case Direction::Left:
			m_Position.x += m_MoveSpeed;
			break;
		case Direction::Right:
			m_Position.x -= m_MoveSpeed;
			break;
		case Direction::Up:
			m_Position.y -= m_MoveSpeed;
			break;
		case Direction::Down:
			m_Position.y += m_MoveSpeed;
			break;
		default:
			break;
		}
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::Move(Direction direction, float speed)
	{
		switch (direction)
		{
		case Direction::Left:
			m_Position.x += speed;
			break;
		case Direction::Right:
			m_Position.x -= speed;
			break;
		case Direction::Up:
			m_Position.y -= speed;
			break;
		case Direction::Down:
			m_Position.y += speed;
			break;
		default:
			break;
		}
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::Rotate(Direction direction)
	{
		switch (direction)
		{
		case Direction::clockwise:
			m_Rotation += m_RotateSpeed;
			break;
		case Direction::counterclockwise:
			m_Rotation -= m_RotateSpeed;
			break;
		default:
			break;
		}
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::Rotate(Direction direction, float speed)
	{
		switch (direction)
		{
		case Direction::clockwise:
			m_Rotation += speed;
			break;
		case Direction::counterclockwise:
			m_Rotation -= speed;
			break;
		default:
			break;
		}
		RecalculateViewMatrix();
	}
}