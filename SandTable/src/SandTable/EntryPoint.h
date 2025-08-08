/**
 * @file SandTable/EntryPoint.h
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#ifndef SANDTABLE_ENTRYPOINT_H
#define SANDTABLE_ENTRYPOINT_H

#ifdef SANDTABLE_PLATFORM_WINDOWS

#include <SandTable.h>

extern SandTable::Application* SandTable::CreateApplication();

int main(int argc, char** argv)
{
	SandTable::Log::Init();
	SANDTABLE_CORE_WARN("SandTable Engine");
	auto app = SandTable::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif