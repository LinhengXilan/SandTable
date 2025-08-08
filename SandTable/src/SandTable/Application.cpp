/**
 * @file Application.cpp
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build5
 */

#include <SandTable/Application.h>
#include <SandTable/Events/Application.h>
#include <SandTable/Log.h>

namespace SandTable
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResize we(1280, 720);
		SANDTABLE_CLIENT_TRACE(we.ToString());
		while (true)
		{
			
		}
	}

}