/**
 * @file SandTable/Events/Mouse.h
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#ifndef SANDTABLE_EVENTS_MOUSE_H
#define SANDTABLE_EVENTS_MOUSE_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL MouseMove : public Event
	{
	public:
		MouseMove(float x, float y)
			: m_MouseX_(x), m_MouseY_(y)
		{

		}

		inline float GetX() const { return m_MouseX_; }
		inline float GetY() const { return m_MouseY_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouveMove: " << m_MouseX_ << ", " << m_MouseY_;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMove; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MouseMove"; }
		virtual int GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input; }

	private:
		float m_MouseX_;
		float m_MouseY_;
	};

	class SANDTABLE_DLL MouseScrolled : public Event
	{
	public:
		MouseScrolled(float x, float y)
			: m_OffsetX_(x), m_OffsetY_(y)
		{
			
		}

		inline float GetXOffset() const { return m_OffsetX_; }
		inline float GetYOffset() const { return m_OffsetY_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScrolled; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MouseScrolled"; }
		virtual int GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input; }

	private:
		float m_OffsetX_;
		float m_OffsetY_;
	};

	class SANDTABLE_DLL MouseButton : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button_; }
		virtual int GetCategoryFlags() const override { return EventCategory::E_Mouse | EventCategory::E_Input | EventCategory::E_MouseButton; }

	protected:
		MouseButton(int button)
			: m_Button_(button)
		{

		}

		int m_Button_;
	};
	
	class SANDTABLE_DLL MousePressed : public MouseButton
	{
	public:
		MousePressed(int button)
			: MouseButton(button)
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_Button_;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MousePressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MousePressed"; }
	};

	class SANDTABLE_DLL MouseReleased : public MouseButton
	{
	public:
		MouseReleased(int button)
			: MouseButton(button)
		{
			
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleased: " << m_Button_;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::MouseReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MouseReleased"; }
	};

}

#endif