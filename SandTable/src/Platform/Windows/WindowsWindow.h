/**
 * @file Platform/Windows/WindowsWindow.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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

		void OnUpdate() override;
		inline const uint16_t GetWidth() const override { return m_WindowData.Width; }
		inline const uint16_t GetHeight() const override { return m_WindowData.Height; }
		inline void* GetNativeWindow() const override { return m_Window.get(); }

		inline void SetEventCallbackFunc(const EventCallbackFunc& callback) override { m_WindowData.EventCallback = callback; }
		void SetSync(bool enabled) override;
		inline const bool IsSync() const override { return m_WindowData.Sync; }

	private:
		virtual void Init(const WindowProperty& property);
		virtual void Shutdown();

	private:
		ObjectRef<GLFWwindow> m_Window;
		struct WindowData
		{
			std::string Title;
			uint16_t Width;
			uint16_t Height;
			bool Sync;
			EventCallbackFunc EventCallback;
		} m_WindowData;
		Object<GraphicsContext> m_Context;
	};
}

#endif