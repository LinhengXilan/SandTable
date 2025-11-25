/**
 * @file SandTable/Events/Keyboard.h
 * @author LinhengXilan 
 * @version build37
 * @date 2025-11-25
 */

#ifndef SANDTABLE_EVENTS_KEYBOARD_H
#define SANDTABLE_EVENTS_KEYBOARD_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL Keyboard : public Event
	{
	public:
		uint32_t GetKeyCode() const;

	protected:
		Keyboard(int keycode);
		virtual ~Keyboard() override = default;
		int m_KeyCode;
	};

	class SANDTABLE_DLL KeyPressed : public Keyboard
	{
	public:
		KeyPressed(int keycode, int repeatcount);
		~KeyPressed() override = default;

	public:
		uint32_t GetRepeatCount() const;

		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;

	private:
		uint32_t m_RepeatCount;
	};

	class SANDTABLE_DLL KeyReleased : public Keyboard
	{
	public:
		KeyReleased(int keycode);
		~KeyReleased() override = default;

	public:
		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL KeyTyped : public Keyboard
	{
	public:
		KeyTyped(int keycode);
		~KeyTyped() override = default;

	public:
		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};
}

#endif