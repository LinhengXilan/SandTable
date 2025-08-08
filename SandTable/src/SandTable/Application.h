/**
 * @file Application.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build5
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SandTable/core.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

#endif