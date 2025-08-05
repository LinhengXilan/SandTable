#ifndef LOG_H
#define LOG_H

#include <memory>

#include <spdlog/spdlog.h>

#include "core.h"

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

#define SANDTABLE_CORE_ERROR(...)	::SandTable::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SANDTABLE_CORE_WARN(...)	::SandTable::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SANDTABLE_CORE_INFO(...)	::SandTable::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SANDTABLE_CORE_TRACE(...)	::SandTable::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SANDTABLE_CORE_FATAL(...)	::SandTable::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define SANDTABLE_CLIENT_ERROR(...)	::SandTable::Log::GetClientLogger()->error(__VA_ARGS__)
#define SANDTABLE_CLIENT_WARN(...)	::SandTable::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SANDTABLE_CLIENT_INFO(...)	::SandTable::Log::GetClientLogger()->info(__VA_ARGS__)
#define SANDTABLE_CLIENT_TRACE(...)	::SandTable::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SANDTABLE_CLIENT_FATAL(...)	::SandTable::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif