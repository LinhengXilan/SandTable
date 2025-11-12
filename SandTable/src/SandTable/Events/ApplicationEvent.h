/**
 * @file SandTable/Events/Application.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_EVENTS_APPLICATIONEVENT_H
#define SANDTABLE_EVENTS_APPLICATIONEVENT_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowResize : public Event
	{
	public:
		WindowResize(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height)
		{
			
		}
		~WindowResize() = default;

	public:
		inline const uint16_t GetWidth() const { return m_Width; }
		inline const uint16_t GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowsResize: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		inline static const EventType GetStaticType() { return EventType::WindowResize; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "WindowResize"; }
		inline const uint8_t GetCategoryFlags() const override { return (int)EventCategory::E_Application; }

	private:
		uint16_t m_Width;
		uint16_t m_Height;
	};

	class SANDTABLE_DLL WindowClose : public Event
	{
	public:
		WindowClose() = default;
		~WindowClose() = default;

		inline static const EventType GetStaticType() { return EventType::WindowClose; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "WindowClose"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Application; }
	};

	class SANDTABLE_DLL AppTick : public Event
	{
	public:
		AppTick();
		~AppTick() = default;

	public:
		inline static const EventType GetStaticType() { return EventType::AppTick; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "AppTick"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Application; }
	};

	class SANDTABLE_DLL AppUpdate : public Event
	{
	public:
		AppUpdate() = default;
		~AppUpdate() = default;

	public:
		inline static const EventType GetStaticType() { return EventType::AppUpdate; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "AppUpdate"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Application; }
	};

	class SANDTABLE_DLL AppRender : public Event
	{
	public:
		AppRender() = default;
		~AppRender() = default;

	public:
		inline static const EventType GetStaticType() { return EventType::AppRender; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "AppRender"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Application; }
	};
}

#endif