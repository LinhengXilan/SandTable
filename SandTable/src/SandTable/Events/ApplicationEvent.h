/**
 * @file SandTable/Events/Application.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#ifndef SANDTABLE_EVENTS_APPLICATIONEVENT_H
#define SANDTABLE_EVENTS_APPLICATIONEVENT_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowResize : public Event
	{
	public:
		WindowResize(unsigned int width, unsigned int height);
		~WindowResize() override = default;

	public:
		const uint16_t GetWidth() const;
		const uint16_t GetHeight() const;

		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;

	private:
		uint16_t m_Width;
		uint16_t m_Height;
	};

	class SANDTABLE_DLL WindowClose : public Event
	{
	public:
		WindowClose() = default;
		~WindowClose() override = default;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppTick : public Event
	{
	public:
		AppTick() = default;
		~AppTick() override = default;

	public:
		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppUpdate : public Event
	{
	public:
		AppUpdate() = default;
		~AppUpdate() override = default;

	public:
		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};

	class SANDTABLE_DLL AppRender : public Event
	{
	public:
		AppRender() = default;
		~AppRender() override = default;

	public:
		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;
	};
}

#endif