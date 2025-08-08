/**
 * @file Log.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build7
 */

#ifndef PLATFORM_WINDOWS_WINDOWSWINDOW_H
#define PLATFORM_WINDOWS_WINDOWSWINDOW_H

#include <GLFW/glfw3.h>

#include <SandTable/Window.h>

namespace SandTable
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperty& property);
		virtual ~WindowsWindow();

		void Update() override;
		inline unsigned int GetWidth() const override { return m_WindowData.Width; }
		inline unsigned int GetHeight() const override { return m_WindowData.Height; }
		inline void SetEventCallbackFunc(const EventCallbackFunc& callback) override { m_WindowData.EventCallback = callback; }
		void SetSync(bool enabled) override;
		bool IsSync() const override;

	private:
		virtual void Init(const WindowProperty& property);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool Sync;
			EventCallbackFunc EventCallback;
		};
		WindowData m_WindowData;
	};
}

#endif