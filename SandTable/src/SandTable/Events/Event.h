/**
 * @file Events/Event.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build5
 */

#ifndef EVENTS_EVENT_H
#define EVENTS_EVENT_H

#include <spdlog/fmt/ostr.h>

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
		None,
		Application = BIT(0),
		Input       = BIT(1),
		Keyboard    = BIT(2),
		Mouse		= BIT(3),
		MouseButton = BIT(4)
	};

	class SANDTABLE_DLL Event
	{
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
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event_(event)
		{

		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
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