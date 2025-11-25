/**
 * @file SandTable/Events/Mouse.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#ifndef SANDTABLE_EVENTS_MOUSEEVENT_H
#define SANDTABLE_EVENTS_MOUSEEVENT_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y);
		~MouseMoved() override = default;

	public:
		float GetX() const;
		float GetY() const;

		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const;
		std::string GetName() const;
		uint8_t GetCategoryFlags() const;

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class SANDTABLE_DLL MouseScrolled : public Event
	{
	public:
		MouseScrolled(float x, float y);
		~MouseScrolled() override = default;

		float GetXOffset() const;
		float GetYOffset() const;

		std::string ToString() const override;

		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
		uint8_t GetCategoryFlags() const override;

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class SANDTABLE_DLL MouseButton : public Event
	{
	public:
		uint32_t GetMouseButton() const;
		virtual uint8_t GetCategoryFlags() const override;

	protected:
		MouseButton(int button);
		virtual ~MouseButton() override = default;

		uint32_t m_Button;
	};
	
	class SANDTABLE_DLL MousePressed : public MouseButton
	{
	public:
		MousePressed(int button);
		~MousePressed() override = default;

	public:
		std::string ToString() const override;
		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
	};

	class SANDTABLE_DLL MouseReleased : public MouseButton
	{
	public:
		MouseReleased(int button);
		~MouseReleased() override = default;

	public:
		std::string ToString() const override;
		static EventType GetStaticType();
		EventType GetEventType() const override;
		std::string GetName() const override;
	};
}

#endif