/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <SandTable/core.h>
#include <SandTable/Events/Event.h>
#include <SandTable/Events/Application.h>
#include <SandTable/Window.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowClose& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	class Application* CreateApplication();

}

#endif