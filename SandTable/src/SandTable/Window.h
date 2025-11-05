/**
 * @file SandTable/Windows.h
 * @author LinhengXilan
 * @date 2025-11-5
 * @version build24
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

		Window() = default;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void SetEventCallbackFunc(const EventCallbackFunc& callback) = 0;
		virtual void SetSync(bool enabled) = 0;
		virtual bool IsSync() const = 0;
		virtual void* GetNativeWindow() const = 0;
		static Window* Create(const WindowProperty& property = WindowProperty());
	};
}

#endif