/**
 * @file SandTable/Core/Application.h
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 * 
 * @brief 应用程序头文件
 */

#ifndef SANDTABLE_CORE_APPLICATION_H
#define SANDTABLE_CORE_APPLICATION_H

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Core/LayerStack.h>
#include <SandTable/Core/Timer/Clock.h>
#include <SandTable/Events/ApplicationEvent.h>
#include <SandTable/ImGui/ImguiLayer.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		const ObjectRef<Window>& GetWindow() const;
		static const ObjectRef<Application>& GetInstance();
		static const ObjectRef<Clock>& GetClock();

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowClose& event);
		bool OnWindowResize(WindowResize& event);

	private:
		static ObjectRef<Application> s_Instance;
		static ObjectRef<Clock> s_Clock;
		bool o_Running = true;
		bool o_Minimized = false;

	private:
		LayerStack m_LayerStack;
		ImguiLayer* m_ImguiLayer;
		ObjectRef<Window> m_Window;
	};

	Object<Application> CreateApplication();
}

#endif