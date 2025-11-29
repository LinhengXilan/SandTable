/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 计时器
 */

#include <pch.h>
#include <SandTable/Core/Timer/Timer.h>

namespace SandTable
{
	/* vvv Timer vvv */

	Timer::Timer(const char* name)
		: m_Name(name), m_TimerGroup(nullptr)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	Timer::Timer(const char* name, const Time& time)
		: m_Name(name), m_StartTimepoint(time.CurrentTime), m_TimerGroup(nullptr)
	{

	}

	Timer::Timer(const char* name, const ObjectRef<TimerGroup>& timerGroup)
		: m_Name(name)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
		m_TimerGroup = timerGroup;
	}

	Timer::~Timer()
	{
		if (o_Stopped == false)
		{
			m_TimerGroup->AddDuration(m_Name, Stop());
		}
	}

	float Timer::Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		int64_t end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		o_Stopped = true;
		float duration = static_cast<float>(end - start) * 0.001;
		return duration;
	}

	/* vvv TimerGroup vvv */

	void TimerGroup::AddDuration(const char* name, float duration)
	{
		m_Durations.emplace_back(name, duration);
	}

	void TimerGroup::ClearDurations()
	{
		m_Durations.clear();
	}

	std::vector<std::pair<std::string, float>>::iterator TimerGroup::begin()
	{
		return m_Durations.begin();
	}

	std::vector<std::pair<std::string, float>>::iterator TimerGroup::end()
	{
		return m_Durations.end();
	}
}