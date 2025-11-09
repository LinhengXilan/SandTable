/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @version build28
 * @date 2025-11-9
 * 
 * @brief 应用程序头文件
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/LayerStack.h>
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Core/Clock.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event& event);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowClose& event);

	private:
		bool m_Running = true;

	private:
		Object<Window> m_Window;
		LayerStack m_LayerStack;
		ImguiLayer* m_ImguiLayer;

		Object<Clock> m_Clock;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

#endif