/**
 * @file SandTable/EntryPoint.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_ENTRYPOINT_H
#define SANDTABLE_ENTRYPOINT_H

#ifdef SANDTABLE_PLATFORM_WINDOWS

#include <SandTable.h>

//extern Object<SandTable::Application> SandTable::CreateApplication();

int main(int argc, char** argv)
{
	SandTable::Log::Init();
	SANDTABLE_CORE_WARN("SandTable Engine");
	SandTable::Object<SandTable::Application> app = SandTable::CreateApplication();
	app->Run();
	app.release();
}

#endif

#endif