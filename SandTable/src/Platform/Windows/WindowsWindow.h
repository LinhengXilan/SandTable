/**
 * @file Platform/Windows/WindowsWindow.h
 * @author LinhengXilan
 * @date 2025-10-25
 * @version build17
 * 
 * @brief Windows平台窗口头文件
 */

#ifndef PLATFORM_WINDOWS_WINDOWSWINDOW_H
#define PLATFORM_WINDOWS_WINDOWSWINDOW_H

#include <SandTable/Renderer/GraphicsContext.h>
#include <SandTable/Window.h>
#include <glfw/glfw.h>

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
		inline virtual void* GetNativeWindow() const override { return m_Window; }

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
		GraphicsContext* m_Context;
	};
}

#endif