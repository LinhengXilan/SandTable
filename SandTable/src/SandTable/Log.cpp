#include "spdlog/sinks/stdout_color_sinks.h"

#include "Log.h"

namespace SandTable
{
	std::shared_ptr<spdlog::logger> Log::CoreLogger_;
	std::shared_ptr<spdlog::logger> Log::ClientLogger_;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n %v%$");
		CoreLogger_ = spdlog::stdout_color_mt("SandTable");
		CoreLogger_->set_level(spdlog::level::trace);
		ClientLogger_ = spdlog::stdout_color_mt("App");
		ClientLogger_->set_level(spdlog::level::trace);
	}
}