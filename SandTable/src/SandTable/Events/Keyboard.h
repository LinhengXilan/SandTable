/**
 * @file SandTable/Events/Keyboard.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
		virtual ~Keyboard() = default;
		int m_KeyCode;
	};

	class SANDTABLE_DLL KeyPressed : public Keyboard
	{
	public:
		KeyPressed(int keycode, int repeatcount);
		~KeyPressed() = default;

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
		~KeyReleased() = default;

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
		~KeyTyped() = default;

	public:
		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};
}

#endif