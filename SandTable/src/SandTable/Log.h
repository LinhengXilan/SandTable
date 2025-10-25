/**
 * @file SandTable/Log.h
 * @author LinhengXilan
 * @date 2025-10-25
 * @version build17
 */

#ifndef SANDTABLE_LOG_H
#define SANDTABLE_LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include <SandTable/core.h>

namespace SandTable
{
	class SANDTABLE_DLL Log
	{
	public:
		Log() = default;
		~Log() = default;

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return CoreLogger_;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return ClientLogger_;
		}
	private:
		static std::shared_ptr<spdlog::logger> CoreLogger_;
		static std::shared_ptr<spdlog::logger> ClientLogger_;
	};
}

// 在引擎内部使用
#define SANDTABLE_CORE_ERROR(...)	::SandTable::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SANDTABLE_CORE_WARN(...)	::SandTable::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SANDTABLE_CORE_INFO(...)	::SandTable::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SANDTABLE_CORE_TRACE(...)	::SandTable::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SANDTABLE_CORE_CRITICAL(...)	::SandTable::Log::GetCoreLogger()->critical(__VA_ARGS__)

// 在客户端使用
#define SANDTABLE_ERROR(...)	::SandTable::Log::GetClientLogger()->error(__VA_ARGS__)
#define SANDTABLE_WARN(...)	::SandTable::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SANDTABLE_INFO(...)	::SandTable::Log::GetClientLogger()->info(__VA_ARGS__)
#define SANDTABLE_TRACE(...)	::SandTable::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SANDTABLE_CRITICAL(...) ::SandTable::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif