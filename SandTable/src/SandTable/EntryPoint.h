/**
 * @file SandTable/EntryPoint.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build7
 */

#ifndef SANDTABLE_ENTRYPOINT_H
#define SANDTABLE_ENTRYPOINT_H

#ifdef SANDTABLE_PLATFORM_WINDOWS

#include <SandTable.h>

extern SandTable::Application* SandTable::CreateApplication();

int main(int argc, char** argv)
{
	SandTable::Log::Init();
	SANDTABLE_CORE_WARN("SandTable");
    int a = 1;
	SANDTABLE_CLIENT_INFO("Hello var={0}", a);
	auto app = SandTable::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif