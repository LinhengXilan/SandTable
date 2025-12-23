/**
 * @file SandTable/EntryPoint.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 */

#ifndef SANDTABLE_ENTRYPOINT_H
#define SANDTABLE_ENTRYPOINT_H

#ifdef SANDTABLE_PLATFORM_WINDOWS

#include <SandTable.h>

int main(int argc, char** argv)
{
	SANDTABLE_PROFILE_BEGIN_SESSION("Startup", "SandTableProfile-Startup.json");
	SandTable::Log::Init();
	SandTable::Object<SandTable::Application> app = SandTable::CreateApplication();
	SANDTABLE_PROFILE_END_SESSION();

	SANDTABLE_PROFILE_BEGIN_SESSION("Runtime", "SandTableProfile-Runtime.json");
	app->Run();
	SANDTABLE_PROFILE_END_SESSION();

	SANDTABLE_PROFILE_BEGIN_SESSION("Shutdown", "SandTableProfile-Shutdown.json");
	app.release();
	SANDTABLE_PROFILE_END_SESSION();
	
	return 0;
}

#endif

#endif