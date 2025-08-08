/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#include <pch.h>

#include <GLFW/glfw3.h>

#include <SandTable/Application.h>
#include <SandTable/Log.h>

namespace SandTable
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallbackFunc(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowClose>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		SANDTABLE_CORE_TRACE("{0}", event.ToString());
	}

	bool Application::OnWindowClose(WindowClose& event)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0.8, 0.8, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->Update();
		}
	}

}