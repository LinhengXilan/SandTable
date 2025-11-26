/**
 * @file SandTable/Log.cpp
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 */

#include <pch.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <SandTable/Core/Log.h>

namespace SandTable
{
	ObjectRef<spdlog::logger> Log::s_CoreLogger;
	ObjectRef<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n %v%$");
#ifdef SANDTABLE_CORE
		s_CoreLogger = spdlog::stdout_color_mt("[SandTable]");
		s_CoreLogger->set_level(spdlog::level::trace);
#endif
		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	const ObjectRef<spdlog::logger>& Log::GetCoreLogger()
	{
		return s_CoreLogger;
	}

	const ObjectRef<spdlog::logger>& Log::GetClientLogger()
	{
		return s_ClientLogger;
	}
}