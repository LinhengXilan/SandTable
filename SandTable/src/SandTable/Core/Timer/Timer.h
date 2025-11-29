/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 计时器
 */
#ifndef SANDTABLE_CORE_TIMER_TIMER_H
	#define SANDTABLE_CORE_TIMER_TIMER_H

#include <SandTable/Core/Core.h>
#include <SandTable/Core/Timer/Clock.h>

namespace SandTable
{
	class TimerGroup
	{
	public:
		TimerGroup() = default;
		~TimerGroup() = default;

	public:
		void AddDuration(const char* name, float duration);

		void ClearDurations();

		std::vector<std::pair<std::string, float>>::iterator begin();
		std::vector<std::pair<std::string, float>>::iterator end();

	private:
		std::vector<std::pair<std::string, float>> m_Durations;
	};

	class Timer
	{
	public:
		Timer(const char* name);
		Timer(const char* name, const Time& time);
		Timer(const char* name, const ObjectRef<TimerGroup>& timerGroup);
		~Timer();

	public:
		float Stop();

	private:
		bool o_Stopped = false;
		const char* m_Name;
		std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
		ObjectRef<TimerGroup> m_TimerGroup;
	};
}

#endif