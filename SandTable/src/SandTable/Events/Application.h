/**
 * @file Events/Application.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build5
 */

#ifndef EVENTS_APPLICATION_H
#define EVENTS_APPLICATION_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowResize : public Event
	{
	public:
		WindowResize(unsigned int width, unsigned int height)
			: m_Width_(width), m_Height_(height)
		{
			
		}

		inline unsigned int GetWidth() const { return m_Width_; }
		inline unsigned int GetHeight() const { return m_Height_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResize: " << m_Width_ << ", " << m_Height_;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowResize; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "WindowResize"; }
		virtual int GetCategoryFlags() const override { return EventCategory::Application; }

	private:
		unsigned int m_Width_;
		unsigned int m_Height_;
	};

	class SANDTABLE_DLL WindowClose : public Event
	{
	public:
		WindowClose() { }

		static EventType GetStaticType() { return EventType::WindowClose; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "WindowClose"; }
		virtual int GetCategoryFlags() const override { return EventCategory::Application; }
	};

	class SANDTABLE_DLL AppTick : public Event
	{
	public:
		AppTick() { }

		static EventType GetStaticType() { return EventType::AppTick; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppTick"; }
		virtual int GetCategoryFlags() const override { return EventCategory::Application; }
	};

	class SANDTABLE_DLL AppUpdate : public Event
	{
	public:
		AppUpdate() { }

		static EventType GetStaticType() { return EventType::AppUpdate; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppUpdate"; }
		virtual int GetCategoryFlags() const override { return EventCategory::Application; }
	};

	class SANDTABLE_DLL AppRender : public Event
	{
	public:
		AppRender() { }

		static EventType GetStaticType() { return EventType::AppRender; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppRender"; }
		virtual int GetCategoryFlags() const override { return EventCategory::Application; }
	};
}

#endif