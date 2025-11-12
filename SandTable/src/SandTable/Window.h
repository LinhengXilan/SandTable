/**
 * @file SandTable/Windows.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_WINDOW_H
#define SANDTABLE_WINDOW_H

#include <pch.h>

#include <SandTable/Core.h>
#include <SandTable/Events/Event.h>

namespace SandTable
{
	struct WindowProperty
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperty(const std::string& title = "SandTable Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	class SANDTABLE_DLL Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

	public:
		Window() = default;
		virtual ~Window() = default;

	public:
		virtual inline const uint16_t GetWidth() const = 0;
		virtual inline const uint16_t GetHeight() const = 0;
		virtual inline void* GetNativeWindow() const = 0;
		virtual inline const bool IsSync() const = 0;

		virtual void SetEventCallbackFunc(const EventCallbackFunc& callback) = 0;
		virtual void SetSync(bool enabled) = 0;

		virtual void OnUpdate() = 0;

		static Object<Window> Create(const WindowProperty& property = WindowProperty());
	};
}

#endif