/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
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
		ObjectRef<Window> GetWindow() const;
		static ObjectRef<Application> GetInstance();

		void Run();
		void PushLayer(ObjectRef<Layer>& layer);
		void PushOverlay(ObjectRef<Layer>& overlay);
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowClose& event);
		bool OnWindowResize(WindowResize& event);

	private:
		static ObjectRef<Application> s_Instance;
		bool m_Running = true;

	private:
		ObjectRef<Window> m_Window;
		LayerStack m_LayerStack;
		ObjectRef<Layer> m_ImguiLayer;
		Object<Clock> m_Clock;
	};

	Object<Application> CreateApplication();
}

#endif