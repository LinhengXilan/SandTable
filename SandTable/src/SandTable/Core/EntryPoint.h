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
	SandTable::Log::Init();
	SandTable::Object<SandTable::Application> app = SandTable::CreateApplication();
	app->Run();
	app.release();
	return 0;
}

#endif

#endif