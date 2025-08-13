/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @date 2025-8-14
 * @version build12
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <SandTable/core.h>
#include <SandTable/Events/Event.h>
#include <SandTable/Events/Application.h>
#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/LayerStack.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowClose& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}

#endif