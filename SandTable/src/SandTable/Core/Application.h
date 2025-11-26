/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 应用程序头文件
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Core/LayerStack.h>
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Core/Clock.h>

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
		void PushLayer(const ObjectRef<Layer>& layer);
		void PushOverlay(const ObjectRef<Layer>& overlay);
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowClose& event);
		bool OnWindowResize(WindowResize& event);

	private:
		static ObjectRef<Application> s_Instance;
		static ObjectRef<Clock> s_Clock;
		bool o_Running = true;

	private:
		LayerStack m_LayerStack;
		ObjectRef<Layer> m_ImguiLayer;
		ObjectRef<Window> m_Window;
	};

	Object<Application> CreateApplication();
}

#endif