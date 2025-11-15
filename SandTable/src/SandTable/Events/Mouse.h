/**
 * @file SandTable/Events/Mouse.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#ifndef SANDTABLE_EVENTS_MOUSE_H
#define SANDTABLE_EVENTS_MOUSE_H

#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL MouseMoved : public Event
	{
	public:
		MouseMoved(float x, float y);

	public:
		const float GetX() const;
		const float GetY() const;

		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const;
		const std::string GetName() const;
		const uint8_t GetCategoryFlags() const;

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class SANDTABLE_DLL MouseScrolled : public Event
	{
	public:
		MouseScrolled(float x, float y);

		const float GetXOffset() const;
		const float GetYOffset() const;

		std::string ToString() const override;

		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
		const uint8_t GetCategoryFlags() const override;

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class SANDTABLE_DLL MouseButton : public Event
	{
	public:
		int GetMouseButton() const;
		virtual const uint8_t GetCategoryFlags() const override;

	protected:
		MouseButton(int button);
		virtual ~MouseButton() = default;

		int m_Button;
	};
	
	class SANDTABLE_DLL MousePressed : public MouseButton
	{
	public:
		MousePressed(int button);

	public:
		std::string ToString() const override;
		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
	};

	class SANDTABLE_DLL MouseReleased : public MouseButton
	{
	public:
		MouseReleased(int button);

	public:
		std::string ToString() const override;
		static const EventType GetStaticType();
		const EventType GetEventType() const override;
		const std::string GetName() const override;
	};
}

#endif