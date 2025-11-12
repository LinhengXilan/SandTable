/**
 * @file SandTable/Log.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_LOG_H
#define SANDTABLE_LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <SandTable/Core.h>

namespace SandTable
{
	class SANDTABLE_DLL Log
	{
	public:
		Log() = default;
		~Log() = default;

	public:
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger_; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger_; }

		static void Init();

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

#ifdef SANDTABLE_ENABLE_ASSERTS
	#define SANDTABLE_ASSERT(x, ...) { if (!(x)) { SANDTABLE_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SANDTABLE_CORE_ASSERT(x, ...) { if (!(x)) { SANDTABLE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SANDTABLE_ASSERT(x, ...)
	#define SANDTABLE_CORE_ASSERT(x, ...)
#endif

// 在客户端使用
#define SANDTABLE_ERROR(...)	::SandTable::Log::GetClientLogger()->error(__VA_ARGS__)
#define SANDTABLE_WARN(...)	::SandTable::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SANDTABLE_INFO(...)	::SandTable::Log::GetClientLogger()->info(__VA_ARGS__)
#define SANDTABLE_TRACE(...)	::SandTable::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SANDTABLE_CRITICAL(...) ::SandTable::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif