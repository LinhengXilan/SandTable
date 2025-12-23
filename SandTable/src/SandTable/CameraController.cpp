/**
 * @file SandTable/CameraController.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 相机控制器
 */

#include <pch.h>
#include <SandTable/CameraController.h>
#include <SandTable/Core/Input.h>
#include <SandTable/Debug/Instrumentor.h>

namespace SandTable
{
	OrthoGraphicCameraController::OrthoGraphicCameraController(float aspectRatio, bool isRotationEnabled, bool enableTranslatedSpeed)
		: m_AspectRatio(aspectRatio), o_Rotation(isRotationEnabled), o_TranslatedSpeed(enableTranslatedSpeed)
	{
		m_Camera = OrthographicCamera::Create(m_AspectRatio, m_ZoomRatio);
	}

	/* vvv Getter vvv */
	const ObjectRef<OrthographicCamera>& OrthoGraphicCameraController::GetCamera() const
	{
		return m_Camera;
	}

	const glm::vec3& OrthoGraphicCameraController::GetPosition() const
	{
		return m_CameraPosition;
	};

	float OrthoGraphicCameraController::GetRotation() const
	{
		return m_CameraRotation;
	};

	float OrthoGraphicCameraController::GetAspectRatio() const
	{
		return m_AspectRatio;
	}

	float OrthoGraphicCameraController::GetZoomRatio() const
	{
		return m_ZoomRatio;
	}

	bool OrthoGraphicCameraController::IsRotationAllowed() const
	{
		return o_Rotation;
	}

	bool OrthoGraphicCameraController::IsTranslatedSpeedAllowed() const
	{
		return o_TranslatedSpeed;
	}

	/* ^^^ Getter ^^^ */
	/* vvv Setter vvv */

	void OrthoGraphicCameraController::SetPosition(const glm::vec3& position)
	{
		m_CameraPosition = position;
		m_Camera->RecalculateViewMatrix(m_CameraPosition, m_CameraRotation);
	}

	void OrthoGraphicCameraController::SetRotation(float rotation)
	{
		m_CameraRotation = rotation;
		m_Camera->RecalculateViewMatrix(m_CameraPosition, m_CameraRotation);
	}

	void OrthoGraphicCameraController::SetMoveSpeed(float speed)
	{
		m_CameraMoveSpeed = speed;
	}

	void OrthoGraphicCameraController::SetTranslatedSpeed(float speed)
	{
		m_CameraMoveSpeed = speed * m_ZoomRatio;
	}

	void OrthoGraphicCameraController::SetRotationSpeed(float speed)
	{
		m_CameraRotationSpeed = speed;
	}

	void OrthoGraphicCameraController::SetZoomRatio(float zoomRatio)
	{
		m_ZoomRatio = zoomRatio;
	}

	/* ^^^ Setter ^^^ */
	/* vvv 选项控制 vvv */

	void OrthoGraphicCameraController::AllowRotation(bool enabled)
	{
		o_Rotation = enabled;
	}

	void OrthoGraphicCameraController::AllowTranslatedSpeed(bool enabled)
	{
		o_TranslatedSpeed = enabled;
	}

	/* ^^^ 选项控制 ^^^ */
	/* vvv  vvv */

	void OrthoGraphicCameraController::Move(Direction direction, float speed, const TimeStep& timeStep)
	{
		SANDTABLE_PROFILE_FUNCTION();
		switch (direction)
		{
		case Direction::Left:
			m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			break;
		case Direction::Right:
			m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			break;
		case Direction::Up:
			m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			m_CameraPosition.y -= cos(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			break;
		case Direction::Down:
			m_CameraPosition.x += -sin(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			m_CameraPosition.y += cos(glm::radians(m_CameraRotation)) * m_CameraMoveSpeed * timeStep.duration;
			break;
		default:
			break;
		}
		m_Camera->RecalculateViewMatrix(m_CameraPosition, m_CameraRotation);
	}

	void OrthoGraphicCameraController::Rotate(Direction direction, float speed, const TimeStep& timeStep)
	{
		switch (direction)
		{
		case Direction::clockwise:
			m_CameraRotation += speed * timeStep.duration;
			break;
		case Direction::counterclockwise:
			m_CameraRotation -= speed * timeStep.duration;
			break;
		default:
			break;
		}

		if (m_CameraRotation > 180.0f)
		{
			m_CameraRotation -= 360.0f;
		}
		else if (m_CameraRotation <= -180.0f)
		{
			m_CameraRotation += 360.0f;
		}
		m_Camera->RecalculateViewMatrix(m_CameraPosition, m_CameraRotation);
	}
	
	/* ^^^  ^^^ */
	/* vvv 事件 vvv */
	
	void OrthoGraphicCameraController::OnUpdate(const TimeStep& timeStep)
	{
		SANDTABLE_PROFILE_FUNCTION();
		if (Input::IsKeyPressed(KEY_W))
		{
			Move(Direction::Up, m_CameraMoveSpeed, timeStep);
		}
		else if (Input::IsKeyPressed(KEY_S))
		{
			Move(Direction::Down, m_CameraMoveSpeed, timeStep);
		}
		if (Input::IsKeyPressed(KEY_A))
		{
			Move(Direction::Left, m_CameraMoveSpeed, timeStep);
		}
		else if (Input::IsKeyPressed(KEY_D))
		{
			Move(Direction::Right, m_CameraMoveSpeed, timeStep);
		}

		if (o_Rotation)
		{
			if (SandTable::Input::IsKeyPressed(KEY_Q))
			{
				Rotate(Direction::counterclockwise, m_CameraRotationSpeed, timeStep);
			}
			else if (SandTable::Input::IsKeyPressed(KEY_E))
			{
				Rotate(Direction::clockwise, m_CameraRotationSpeed, timeStep);
			}
		}

		if (SandTable::Input::IsKeyPressed(KEY_R))
		{
			SetPosition({0.0f, 0.0f, 0.0f});
			SetRotation(0.0f);
		}
	}

	void OrthoGraphicCameraController::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolled>(SANDTABLE_BIND_EVENT_FUNC(OrthoGraphicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResize>(SANDTABLE_BIND_EVENT_FUNC(OrthoGraphicCameraController::OnWindowResized));
	}

	PRIVATE bool OrthoGraphicCameraController::OnMouseScrolled(MouseScrolled& event)
	{
		if (o_TranslatedSpeed) [[likely]]
		{
			m_CameraMoveSpeed /= m_ZoomRatio;
			m_ZoomRatio -= event.GetYOffset() * 0.5f;
			m_ZoomRatio = std::max(m_ZoomRatio, 0.25f);
			m_CameraMoveSpeed *= m_ZoomRatio;
			m_Camera->SetProjectionMatrix(m_AspectRatio, m_ZoomRatio);
			return false;
		}
		m_ZoomRatio -= event.GetYOffset() * 0.5f;
		m_ZoomRatio = std::max(m_ZoomRatio, 0.25f);
		m_Camera->SetProjectionMatrix(m_AspectRatio, m_ZoomRatio);
		return false;
	}

	PRIVATE bool OrthoGraphicCameraController::OnWindowResized(WindowResize& event)
	{
		m_AspectRatio = (float)event.GetWidth() / (float)event.GetHeight();
		m_Camera->SetProjectionMatrix(m_AspectRatio, m_ZoomRatio);
		return false;
	}

	/* ^^^ 事件 ^^^ */
}