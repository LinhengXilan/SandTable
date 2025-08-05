#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"

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