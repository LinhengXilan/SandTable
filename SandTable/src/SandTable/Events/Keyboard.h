/**
 * @file SandTable/Events/Keyboard.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_EVENTS_KEYBOARD_H
#define SANDTABLE_EVENTS_KEYBOARD_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL Keyboard : public Event
	{
	public:
		inline const int GetKeyCode() const { return m_KeyCode; }

	protected:
		Keyboard(int keycode)
			: m_KeyCode(keycode)
		{
			
		}
		virtual ~Keyboard() = default;
		int m_KeyCode;
	};

	class SANDTABLE_DLL KeyPressed : public Keyboard
	{
	public:
		KeyPressed(int keycode, int repeatcount)
		  : Keyboard(keycode), m_RepeatCount(repeatcount)
		{
		  
		}
		~KeyPressed() = default;

	public:
		inline const int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		inline static const EventType GetStaticType() { return EventType::KeyPressed; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "KeyPressed"; }
        inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }

	private:
		int m_RepeatCount;
	};

	class SANDTABLE_DLL KeyReleased : public Keyboard
	{
	public:
		KeyReleased(int keycode)
			: Keyboard(keycode)
		{

		}
		~KeyReleased() = default;

	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << m_KeyCode;
			return ss.str();
		}

		inline static const EventType GetStaticType() { return EventType::KeyReleased; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "KeyReleased"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }
	};

	class SANDTABLE_DLL KeyTyped : public Keyboard
	{
	public:
		KeyTyped(int keycode)
			: Keyboard(keycode)
		{

		}
		~KeyTyped() = default;

	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTyped: " << m_KeyCode;
			return ss.str();
		}

		inline static const EventType GetStaticType() { return EventType::KeyTyped; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "KeyTyped"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }
	};
}

#endif