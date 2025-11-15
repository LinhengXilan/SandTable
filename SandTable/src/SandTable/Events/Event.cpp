/**
 * @file SandTable/Events/Event.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#include <pch.h>
#include <SandTable/Events/Event.h>

namespace SandTable
{
	const bool Event::IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}

	std::string Event::ToString() const
	{
		return GetName();
	}


	EventDispatcher::EventDispatcher(Event& event)
		: m_Event(event)
	{

	}

	std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}
