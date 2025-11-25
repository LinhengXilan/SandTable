/**
 * @file SandTable/Windows.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#ifndef SANDTABLE_WINDOW_H
#define SANDTABLE_WINDOW_H

#include <pch.h>

#include <SandTable/Core/Core.h>
#include <SandTable/Events/Event.h>

namespace SandTable
{
	struct WindowProperty
	{
		std::string Title;
		int Width;
		int Height;

		WindowProperty(const std::string& title = "SandTable Engine", int32_t width = 1280, int32_t height = 720)
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
		virtual int32_t GetWidth() const = 0;
		virtual int32_t GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual bool IsSync() const = 0;

		virtual void SetEventCallbackFunc(const EventCallbackFunc& callback) = 0;
		virtual void SetSync(bool enabled) = 0;

		virtual void OnUpdate() = 0;

		static ObjectRef<Window> Create(const WindowProperty& property = WindowProperty());
	};
}

#endif