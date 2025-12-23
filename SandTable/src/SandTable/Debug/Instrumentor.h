/**
 * @file SandTable/Debug/Instrumentor.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 性能探查器
 */

#ifndef SANDTABLE_DEBUG_INSTRUMENTOR_H
	#define SANDTABLE_DEBUG_INSTRUMENTOR_H

#include <SandTable/Core/Core.h>

namespace SandTable
{
	struct ProfileResult
	{
		std::string Name;
		int64_t Start;
		int64_t End;
		uint32_t ThreadID;
	};

	struct InstrumentationSession
	{
		std::string Name;
	};

	class Instrumentor
	{
	public:
		Instrumentor();
		~Instrumentor() = default;

	public:
		void BeginSession(const std::string& name, const std::string& filepath = "results.json");
		void EndSession();
		void WriteProfile(const ProfileResult& result);
		void WriteHeader();
		void WriteFooter();
		static Instrumentor& Get();

	private:
		InstrumentationSession* m_CurrentSession;
		std::ofstream m_OutputStream;
		uint64_t m_ProfileCount;
	};

	class InstrumentationTimer
	{
	public:
		InstrumentationTimer(const char* name);
		~InstrumentationTimer();

	public:
		void Stop();

	private:
		const char* m_Name;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
		bool m_Stopped;
	};

#ifdef SANDTABLE_PROFILE
	#define SANDTABLE_PROFILE_BEGIN_SESSION(name, filepath) ::SandTable::Instrumentor::Get().BeginSession(name, filepath)
	#define SANDTABLE_PROFILE_END_SESSION() ::SandTable::Instrumentor::Get().EndSession()
	#define SANDTABLE_PROFILE_SCOPE(name) ::SandTable::InstrumentationTimer timer##__LINE__(name);
	#define SANDTABLE_PROFILE_FUNCTION() SANDTABLE_PROFILE_SCOPE(__FUNCSIG__)
#else
	#define SANDTABLE_PROFILE_BEGIN_SESSION(name, filepath)
	#define SANDTABLE_PROFILE_END_SESSION()
	#define SANDTABLE_PROFILE_SCOPE(name)
	#define SANDTABLE_PROFILE_FUNCTION()
#endif
}

#endif