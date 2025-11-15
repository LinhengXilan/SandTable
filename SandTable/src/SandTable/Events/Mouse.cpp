/**
 * @file SandTable/Events/Mouse.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#include <pch.h>
#include <SandTable/Events/Mouse.h>

namespace SandTable
{
	MouseMoved::MouseMoved(float x, float y)
		: m_MouseX(x), m_MouseY(y)
	{

	}

	const float MouseMoved::GetX() const
	{
		return m_MouseX;
	}

	const float MouseMoved::GetY() const
	{
		return m_MouseY;
	}

	std::string MouseMoved::ToString() const
	{
		std::stringstream ss;
		ss << "MouveMove: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	const EventType MouseMoved::GetStaticType()
	{
		return EventType::MouseMoved;
	}

	const EventType MouseMoved::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string MouseMoved::GetName() const
	{
		return "MouseMoved";
	}

	const uint8_t MouseMoved::GetCategoryFlags() const
	{
		return EventCategory::E_Mouse | EventCategory::E_Input;
	}

	MouseScrolled::MouseScrolled(float x, float y)
		: m_OffsetX(x), m_OffsetY(y)
	{

	}

	const float MouseScrolled::GetXOffset() const
	{
		return m_OffsetX;
	}

	const float MouseScrolled::GetYOffset() const
	{
		return m_OffsetY;
	}

	std::string MouseScrolled::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	const EventType MouseScrolled::GetStaticType()
	{
		return EventType::MouseScrolled;
	}

	const EventType MouseScrolled::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string MouseScrolled::GetName() const
	{
		return "MouseScrolled";
	}

	const uint8_t MouseScrolled::GetCategoryFlags() const
	{
		return EventCategory::E_Mouse | EventCategory::E_Input;
	}

	int MouseButton::GetMouseButton() const
	{
		return m_Button;
	}

	const uint8_t MouseButton::GetCategoryFlags() const
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

	const EventType MousePressed::GetStaticType()
	{
		return EventType::MousePressed;
	}

	const EventType MousePressed::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string MousePressed::GetName() const
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

	const EventType MouseReleased::GetStaticType()
	{
		return EventType::MouseReleased;
	}

	const EventType MouseReleased::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string MouseReleased::GetName() const
	{
		return "MouseReleased";
	}
}