/**
 * @file SandTable/Events/Keyboard.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#include <pch.h>
#include <SandTable/Events/Keyboard.h>

namespace SandTable
{

	const int Keyboard::GetKeyCode() const
	{
		return m_KeyCode;
	}

	Keyboard::Keyboard(int keycode)
		: m_KeyCode(keycode)
	{

	}

	KeyPressed::KeyPressed(int keycode, int repeatcount)
		: Keyboard(keycode), m_RepeatCount(repeatcount)
	{

	}

	const int KeyPressed::GetRepeatCount() const
	{
		return m_RepeatCount;
	}

	std::string KeyPressed::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressed: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	const EventType KeyPressed::GetStaticType()
	{
		return EventType::KeyPressed;
	}

	const EventType KeyPressed::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string KeyPressed::GetName() const
	{
		return "KeyPressed";
	}

	const uint8_t KeyPressed::GetCategoryFlags() const
	{
		return EventCategory::E_Keyboard | EventCategory::E_Input;
	}


	KeyReleased::KeyReleased(int keycode)
		: Keyboard(keycode)
	{

	}

	std::string KeyReleased::ToString() const
	{
		std::stringstream ss;
		ss << "KeyReleased: " << m_KeyCode;
		return ss.str();
	}

	const EventType KeyReleased::GetStaticType()
	{
		return EventType::KeyReleased;
	}

	const EventType KeyReleased::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string KeyReleased::GetName() const
	{
		return "KeyReleased";
	}

	const uint8_t KeyReleased::GetCategoryFlags() const
	{
		return EventCategory::E_Keyboard | EventCategory::E_Input;
	}


	KeyTyped::KeyTyped(int keycode)
		: Keyboard(keycode)
	{

	}

	std::string KeyTyped::ToString() const
	{
		std::stringstream ss;
		ss << "KeyTyped: " << m_KeyCode;
		return ss.str();
	}

	const EventType KeyTyped::GetStaticType()
	{
		return EventType::KeyTyped;
	}

	const EventType KeyTyped::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string KeyTyped::GetName() const
	{
		return "KeyTyped";
	}

	const uint8_t KeyTyped::GetCategoryFlags() const
	{
		return EventCategory::E_Keyboard | EventCategory::E_Input;
	}
}