/**
 * @file Platform/OpenGL/OpenGLCamera.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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

	const CameraType OpenGLOrthographicCamera::GetCameraType() const
	{
		return CameraType::Orthographic;
	};

	const glm::vec3& OpenGLOrthographicCamera::GetPosition() const
	{
		return m_Position;
	};

	const float OpenGLOrthographicCamera::GetRotation() const
	{
		return m_Rotation;
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

	void OpenGLOrthographicCamera::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		RecalculateViewMatrix();
	}

	void OpenGLOrthographicCamera::SetRotation(const float rotation)
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

	void OpenGLOrthographicCamera::SetMoveSpeed(const float speed)
	{
		m_MoveSpeed = speed;
	}

	void OpenGLOrthographicCamera::SetRotateSpeed(const float speed)
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

	void OpenGLOrthographicCamera::Move(Direction direction, TimeStep timeStep)
	{
		switch (direction)
		{
		case Direction::Left:
			m_Position.x += m_MoveSpeed * timeStep.duration;
			break;
		case Direction::Right:
			m_Position.x -= m_MoveSpeed * timeStep.duration;
			break;
		case Direction::Up:
			m_Position.y -= m_MoveSpeed * timeStep.duration;
			break;
		case Direction::Down:
			m_Position.y += m_MoveSpeed * timeStep.duration;
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

	void OpenGLOrthographicCamera::Move(Direction direction, float speed, TimeStep timeStep)
	{
		switch (direction)
		{
		case Direction::Left:
			m_Position.x += speed * timeStep.duration;
			break;
		case Direction::Right:
			m_Position.x -= speed * timeStep.duration;
			break;
		case Direction::Up:
			m_Position.y -= speed * timeStep.duration;
			break;
		case Direction::Down:
			m_Position.y += speed * timeStep.duration;
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

	void OpenGLOrthographicCamera::Rotate(Direction direction, TimeStep timeStep)
	{
		switch (direction)
		{
		case Direction::clockwise:
			m_Rotation += m_RotateSpeed * timeStep.duration;
			break;
		case Direction::counterclockwise:
			m_Rotation -= m_RotateSpeed * timeStep.duration;
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

	void OpenGLOrthographicCamera::Rotate(Direction direction, float speed, TimeStep timeStep)
	{
		switch (direction)
		{
		case Direction::clockwise:
			m_Rotation += speed * timeStep.duration;
			break;
		case Direction::counterclockwise:
			m_Rotation -= speed * timeStep.duration;
			break;
		default:
			break;
		}
		RecalculateViewMatrix();
	}
}