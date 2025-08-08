/**
 * @file SandTable/Events/Event.h
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#ifndef SANDTABLE_EVENTS_EVENT_H
#define SANDTABLE_EVENTS_EVENT_H

#include <pch.h>

#include <SandTable/Core.h>

namespace SandTable
{
	enum class EventType : unsigned char
	{
		None,
		WindowClose, WindowResize, WindowFocus, WindowFocusLost, WindowMove,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MousePressed, MouseReleased, MouseMove, MouseScrolled
	};

	enum EventCategory
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
		~Event() = default;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
	protected:
		bool m_Handled_ = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event_(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_Event_.GetEventType() == T::GetStaticType())
			{
				m_Event_.m_Handled_ = func(*(T*)&m_Event_);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event_;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
	
}

#endif