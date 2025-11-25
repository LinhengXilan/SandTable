/**
 * @file SandTable/Events/Application.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#include <pch.h>
#include <SandTable/Events/ApplicationEvent.h>

namespace SandTable
{
	WindowResize::WindowResize(int32_t width, int32_t height)
		: m_Width(width), m_Height(height)
	{

	}
	
	int32_t WindowResize::GetWidth() const
	{
		return m_Width;
	}

	int32_t WindowResize::GetHeight() const
	{
		return m_Height;
	}
	
	std::string WindowResize::ToString() const
	{
		std::stringstream ss;
		ss << "WindowsResize: " << m_Width << ", " << m_Height;
		return ss.str();
	}
	
	EventType WindowResize::GetStaticType()
	{
		return EventType::WindowResize;
	}

	EventType WindowResize::GetEventType() const
	{
		return GetStaticType();
	}

	std::string WindowResize::GetName() const
	{
		return "WindowResize";
	}

	uint8_t WindowResize::GetCategoryFlags() const
	{
		return (int)EventCategory::E_Application;
	}


	EventType WindowClose::GetStaticType()
	{
		return EventType::WindowClose;
	}

	EventType WindowClose::GetEventType() const
	{
		return GetStaticType();
	}

	std::string WindowClose::GetName() const
	{
		return "WindowClose";
	}

	uint8_t WindowClose::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	EventType AppTick::GetStaticType()
	{
		return EventType::AppTick;
	}

	EventType AppTick::GetEventType() const
	{
		return GetStaticType();
	}

	std::string AppTick::GetName() const
	{
		return "AppTick";
	}

	uint8_t AppTick::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	EventType AppUpdate::GetStaticType()
	{
		return EventType::AppUpdate;
	}

	EventType AppUpdate::GetEventType() const
	{
		return GetStaticType();
	}

	std::string AppUpdate::GetName() const
	{
		return "AppUpdate";
	}

	uint8_t AppUpdate::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}


	EventType AppRender::GetStaticType()
	{
		return EventType::AppRender;
	}

	EventType AppRender::GetEventType() const
	{
		return GetStaticType();
	}

	std::string AppRender::GetName() const
	{
		return "AppRender";
	}

	uint8_t AppRender::GetCategoryFlags() const
	{
		return EventCategory::E_Application;
	}
}