/**
 * @file SandTable/Core/EntryPoint.h
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 */

#ifndef SANDTABLE_CORE_ENTRYPOINT_H
#define SANDTABLE_CORE_ENTRYPOINT_H

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