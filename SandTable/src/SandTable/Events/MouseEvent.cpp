/**
 * @file SandTable/Events/Mouse.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#include <pch.h>
#include <SandTable/Events/MouseEvent.h>

namespace SandTable
{
	MouseMoved::MouseMoved(float x, float y)
		: m_MouseX(x), m_MouseY(y)
	{

	}

	float MouseMoved::GetX() const
	{
		return m_MouseX;
	}

	float MouseMoved::GetY() const
	{
		return m_MouseY;
	}

	std::string MouseMoved::ToString() const
	{
		std::stringstream ss;
		ss << "MouveMove: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	EventType MouseMoved::GetStaticType()
	{
		return EventType::MouseMoved;
	}

	EventType MouseMoved::GetEventType() const
	{
		return GetStaticType();
	}

	std::string MouseMoved::GetName() const
	{
		return "MouseMoved";
	}

	uint8_t MouseMoved::GetCategoryFlags() const
	{
		return EventCategory::E_Mouse | EventCategory::E_Input;
	}

	MouseScrolled::MouseScrolled(float x, float y)
		: m_OffsetX(x), m_OffsetY(y)
	{

	}

	float MouseScrolled::GetXOffset() const
	{
		return m_OffsetX;
	}

	float MouseScrolled::GetYOffset() const
	{
		return m_OffsetY;
	}

	std::string MouseScrolled::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	EventType MouseScrolled::GetStaticType()
	{
		return EventType::MouseScrolled;
	}

	EventType MouseScrolled::GetEventType() const
	{
		return GetStaticType();
	}

	std::string MouseScrolled::GetName() const
	{
		return "MouseScrolled";
	}

	uint8_t MouseScrolled::GetCategoryFlags() const
	{
		return EventCategory::E_Mouse | EventCategory::E_Input;
	}

	uint32_t MouseButton::GetMouseButton() const
	{
		return m_Button;
	}

	uint8_t MouseButton::GetCategoryFlags() const
	{
		return EventCategory::E_Mouse | EventCategory::E_Input | EventCategory::E_MouseButton;
	}

	MouseButton::MouseButton(int button)
		: m_Button(button)
	{

	}

	MousePressed::MousePressed(int button)
		: MouseButton(button)
	{

	}

	std::string MousePressed::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressed: " << m_Button;
		return ss.str();
	}

	EventType MousePressed::GetStaticType()
	{
		return EventType::MousePressed;
	}

	EventType MousePressed::GetEventType() const
	{
		return GetStaticType();
	}

	std::string MousePressed::GetName() const
	{
		return "MousePressed";
	}

	MouseReleased::MouseReleased(int button)
		: MouseButton(button)
	{

	}

	std::string MouseReleased::ToString() const
	{
		std::stringstream ss;
		ss << "MouseReleased: " << m_Button;
		return ss.str();
	}

	EventType MouseReleased::GetStaticType()
	{
		return EventType::MouseReleased;
	}

	EventType MouseReleased::GetEventType() const
	{
		return GetStaticType();
	}

	std::string MouseReleased::GetName() const
	{
		return "MouseReleased";
	}
}