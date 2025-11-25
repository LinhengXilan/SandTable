/**
 * @file Platform/Windows/WindowsWindow.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief Windows平台窗口头文件
 */

#ifndef PLATFORM_WINDOWS_WINDOWSWINDOW_H
#define PLATFORM_WINDOWS_WINDOWSWINDOW_H

#include <SandTable/Renderer/GraphicsContext.h>
#include <SandTable/Core/Window.h>
#include <glfw/glfw.h>

namespace SandTable
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperty& property);
		~WindowsWindow() override;

		int32_t GetWidth() const override;
		int32_t GetHeight() const override;
		void* GetNativeWindow() const override;
		bool IsSync() const override;

		void SetEventCallbackFunc(const EventCallbackFunc& callback) override;
		void SetSync(bool enabled) override;
		void OnUpdate() override;

	private:
		virtual void Init(const WindowProperty& property);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;
		Object<GraphicsContext> m_Context;
		struct WindowData
		{
			std::string Title;
			uint16_t Width = 0;
			uint16_t Height = 0;
			bool Sync = false;
			EventCallbackFunc EventCallback;
		} m_WindowData;
	};
}

#endif