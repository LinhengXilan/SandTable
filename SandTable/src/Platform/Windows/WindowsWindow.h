/**
 * @file Platform/Windows/WindowsWindow.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
		~WindowsWindow();

		const uint16_t GetWidth() const override;
		const uint16_t GetHeight() const override;
		void* GetNativeWindow() const override;
		const bool IsSync() const override;

		void SetEventCallbackFunc(const EventCallbackFunc& callback) override;
		void SetSync(bool enabled) override;
		void OnUpdate() override;

	private:
		virtual void Init(const WindowProperty& property);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			uint16_t Width = 0;
			uint16_t Height = 0;
			bool Sync = false;
			EventCallbackFunc EventCallback;
		} m_WindowData;
		Object<GraphicsContext> m_Context;
	};
}

#endif