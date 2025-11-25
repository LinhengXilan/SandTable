/**
 * @file SandTable/Events/Keyboard.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#include <pch.h>
#include <SandTable/Events/Keyboard.h>

namespace SandTable
{

	uint32_t Keyboard::GetKeyCode() const
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

	uint32_t KeyPressed::GetRepeatCount() const
	{
		return m_RepeatCount;
	}

	std::string KeyPressed::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressed: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	EventType KeyPressed::GetStaticType()
	{
		return EventType::KeyPressed;
	}

	EventType KeyPressed::GetEventType() const
	{
		return GetStaticType();
	}

	std::string KeyPressed::GetName() const
	{
		return "KeyPressed";
	}

	uint8_t KeyPressed::GetCategoryFlags() const
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

	EventType KeyReleased::GetStaticType()
	{
		return EventType::KeyReleased;
	}

	EventType KeyReleased::GetEventType() const
	{
		return GetStaticType();
	}

	std::string KeyReleased::GetName() const
	{
		return "KeyReleased";
	}

	uint8_t KeyReleased::GetCategoryFlags() const
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

	EventType KeyTyped::GetStaticType()
	{
		return EventType::KeyTyped;
	}

	EventType KeyTyped::GetEventType() const
	{
		return GetStaticType();
	}

	std::string KeyTyped::GetName() const
	{
		return "KeyTyped";
	}

	uint8_t KeyTyped::GetCategoryFlags() const
	{
		return EventCategory::E_Keyboard | EventCategory::E_Input;
	}
}