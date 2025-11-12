/**
 * @file SandTable/Events/Mouse.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_EVENTS_MOUSE_H
#define SANDTABLE_EVENTS_MOUSE_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{

		}

	public:
		inline const float GetX() const { return m_MouseX; }
		inline const float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouveMove: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		static const EventType GetStaticType() { return EventType::MouseMoved; }
		const EventType GetEventType() const override { return GetStaticType(); }
		const std::string GetName() const override { return "MouseMoved"; }
		const uint8_t GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input; }

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class SANDTABLE_DLL MouseScrolled : public Event
	{
	public:
		MouseScrolled(float x, float y)
			: m_OffsetX(x), m_OffsetY(y)
		{
			
		}

		inline const float GetXOffset() const { return m_OffsetX; }
		inline const float GetYOffset() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		inline static const EventType GetStaticType() { return EventType::MouseScrolled; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "MouseScrolled"; }
		inline const uint8_t GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input; }

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class SANDTABLE_DLL MouseButton : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		inline virtual const uint8_t GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input | EventCategory::E_MouseButton; }

	protected:
		MouseButton(int button)
			: m_Button(button)
		{

		}
		virtual ~MouseButton() = default;

		int m_Button;
	};
	
	class SANDTABLE_DLL MousePressed : public MouseButton
	{
	public:
		MousePressed(int button)
			: MouseButton(button)
		{

		}

	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_Button;
			return ss.str();
		}
		inline static const EventType GetStaticType() { return EventType::MousePressed; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "MousePressed"; }
	};

	class SANDTABLE_DLL MouseReleased : public MouseButton
	{
	public:
		MouseReleased(int button)
			: MouseButton(button)
		{
			
		}

	public:
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleased: " << m_Button;
			return ss.str();
		}
		inline static const EventType GetStaticType() { return EventType::MouseReleased; }
		inline const EventType GetEventType() const override { return GetStaticType(); }
		inline const std::string GetName() const override { return "MouseReleased"; }
	};
}

#endif