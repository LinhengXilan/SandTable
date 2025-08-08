/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build7
 */

#include <pch.h>

#include <GLFW/glfw3.h>

#include <SandTable/Application.h>
#include <SandTable/Events/Application.h>
#include <SandTable/Log.h>

namespace SandTable
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

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