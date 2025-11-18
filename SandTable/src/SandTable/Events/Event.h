/**
 * @file SandTable/Events/Event.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 */

#ifndef SANDTABLE_EVENTS_EVENT_H
#define SANDTABLE_EVENTS_EVENT_H

#include <SandTable/Core.h>

namespace SandTable
{
	enum class EventType : unsigned char
	{
		None,
		WindowClose, WindowResize, WindowFocus, WindowFocusLost, WindowMove,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MousePressed, MouseReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory : uint8_t
	{
		E_None,
		E_Application	= BIT(0),
		E_Input			= BIT(1),
		E_Keyboard		= BIT(2),
		E_Mouse			= BIT(3),
		E_MouseButton	= BIT(4)
	};

	class SANDTABLE_DLL Event
	{
		friend class EventDispatcher;
	public:
		Event() = default;
		virtual ~Event() = default;
	public:
		virtual const EventType GetEventType() const = 0;
		virtual const std::string GetName() const = 0;
		virtual const uint8_t GetCategoryFlags() const = 0;
		const bool IsInCategory(EventCategory category);
		virtual std::string ToString() const;

	public:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event);
		~EventDispatcher() = default;

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	std::ostream& operator<<(std::ostream& os, const Event& event);
}

#endif