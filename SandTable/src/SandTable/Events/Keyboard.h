/**
 * @file SandTable/Events/Keyboard.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 */

#ifndef SANDTABLE_EVENTS_KEYBOARD_H
#define SANDTABLE_EVENTS_KEYBOARD_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL Keyboard : public Event
	{
	public:
		const int GetKeyCode() const;

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
		const int GetRepeatCount() const;

		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;

	private:
		int m_RepeatCount;
	};

	class SANDTABLE_DLL KeyReleased : public Keyboard
	{
	public:
		KeyReleased(int keycode);
		~KeyReleased() override = default;

	public:
		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL KeyTyped : public Keyboard
	{
	public:
		KeyTyped(int keycode);
		~KeyTyped() override = default;

	public:
		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};
}

#endif