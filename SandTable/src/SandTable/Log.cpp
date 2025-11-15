/**
 * @file SandTable/Log.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 */

#include <pch.h>

#include <spdlog/sinks/stdout_color_sinks.h>

#include <SandTable/Log.h>

namespace SandTable
{
	std::shared_ptr<spdlog::logger> Log::CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n %v%$");
		CoreLogger = spdlog::stdout_color_mt("[SandTable]");
		CoreLogger->set_level(spdlog::level::trace);
		ClientLogger = spdlog::stdout_color_mt("App");
		ClientLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return CoreLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return ClientLogger;
	}
}