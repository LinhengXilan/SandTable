/**
 * @file SandTable/Events/Keyboard.h
 * @author LinhengXilan
 * @date 2025-8-14
 * @version build12
 */

#ifndef SANDTABLE_EVENTS_KEYBOARD_H
#define SANDTABLE_EVENTS_KEYBOARD_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL Keyboard : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode_; }

	protected:
		Keyboard(int keycode)
			: m_KeyCode_(keycode)
		{
			
		}

		int m_KeyCode_;
	};

	class SANDTABLE_DLL KeyPressed : public Keyboard
	{
	public:
		KeyPressed(int keycode, int repeatcount)
		  : Keyboard(keycode), m_RepeatCount_(repeatcount)
		{
		  
		}

		inline int GetRepeatCount() const { return m_RepeatCount_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << m_KeyCode_ << "(" << m_RepeatCount_ << " repeats)";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "KeyPressed"; }
        virtual int GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }

	private:
		int m_RepeatCount_;
	};

	class SANDTABLE_DLL KeyReleased : public Keyboard
	{
	public:
		KeyReleased(int keycode)
			: Keyboard(keycode)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << m_KeyCode_;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char *GetName() const override { return "KeyReleased"; }
		virtual int GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }
	};

	class SANDTABLE_DLL KeyTyped : public Keyboard
	{
	public:
		KeyTyped(int keycode)
			: Keyboard(keycode)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTyped: " << m_KeyCode_;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyTyped; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "KeyTyped"; }
		virtual int GetCategoryFlags() const override { return EventCategory::E_Keyboard | EventCategory::E_Input; }
	};
}

#endif