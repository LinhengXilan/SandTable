/**
 * @file SandTable/Events/Application.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#include <pch.h>
#include <SandTable/Events/ApplicationEvent.h>

namespace SandTable
{
	WindowResize::WindowResize(unsigned int width, unsigned int height)
		: m_Width(width), m_Height(height)
	{

	}
	
	const uint16_t WindowResize::GetWidth() const
	{
		return m_Width;
	}

	const uint16_t WindowResize::GetHeight() const
	{
		return m_Height;
	}
	
	std::string WindowResize::ToString() const
	{
		std::stringstream ss;
		ss << "WindowsResize: " << m_Width << ", " << m_Height;
		return ss.str();
	}
	
	const EventType WindowResize::GetStaticType()
	{
		return EventType::WindowResize;
	}

	const EventType WindowResize::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string WindowResize::GetName() const
	{
		return "WindowResize";
	}

	const uint8_t WindowResize::GetCategoryFlags() const
	{
		return (int)EventCategory::E_Application;
	}


	const EventType WindowClose::GetStaticType()
	{
		return EventType::WindowClose;
	}

	const EventType WindowClose::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string WindowClose::GetName() const
	{
		return "WindowClose";
	}

	const uint8_t WindowClose::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	const EventType AppTick::GetStaticType()
	{
		return EventType::AppTick;
	}

	const EventType AppTick::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string AppTick::GetName() const
	{
		return "AppTick";
	}

	const uint8_t AppTick::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	const EventType AppUpdate::GetStaticType()
	{
		return EventType::AppUpdate;
	}

	const EventType AppUpdate::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string AppUpdate::GetName() const
	{
		return "AppUpdate";
	}

	const uint8_t AppUpdate::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	const EventType AppRender::GetStaticType()
	{
		return EventType::AppRender;
	}

	const EventType AppRender::GetEventType() const
	{
		return GetStaticType();
	}

	const std::string AppRender::GetName() const
	{
		return "AppRender";
	}

	const uint8_t AppRender::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}
}