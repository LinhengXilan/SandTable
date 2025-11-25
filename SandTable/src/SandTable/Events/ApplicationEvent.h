/**
 * @file SandTable/Events/Application.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#ifndef SANDTABLE_EVENTS_APPLICATIONEVENT_H
#define SANDTABLE_EVENTS_APPLICATIONEVENT_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowResize : public Event
	{
	public:
		WindowResize(int32_t width, int32_t height);
		~WindowResize() override = default;

	public:
		int32_t GetWidth() const;
		int32_t GetHeight() const;

		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;

	private:
		int32_t m_Width;
		int32_t m_Height;
	};

	class SANDTABLE_DLL WindowClose : public Event
	{
	public:
		WindowClose() = default;
		~WindowClose() override = default;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppTick : public Event
	{
	public:
		AppTick() = default;
		~AppTick() override = default;

	public:
		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppUpdate : public Event
	{
	public:
		AppUpdate() = default;
		~AppUpdate() override = default;

	public:
		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppRender : public Event
	{
	public:
		AppRender() = default;
		~AppRender() override = default;

	public:
		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;
	};
}

#endif