/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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

	public:
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; }

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowClose& event);

	private:
		static Application* s_Instance;
		bool m_Running = true;

	private:
		Object<Window> m_Window;
		LayerStack m_LayerStack;
		Object<ImguiLayer> m_ImguiLayer;
		Object<Clock> m_Clock;

	};

	Object<Application> CreateApplication();
}

#endif