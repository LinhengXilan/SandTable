/**
 * @file SandTable/Core/Clock.cpp
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 时钟
 */

#include <pch.h>
#include <SandTable/Core/Timer/Clock.h>

namespace SandTable
{
	Time::Time(std::chrono::time_point<std::chrono::steady_clock> time)
		: CurrentTime(time), LastTime(time), Timestep({0.0f})
	{

	}

	Clock::Clock()
		: m_Time(std::chrono::high_resolution_clock::now())
	{

	}

	std::chrono::time_point<std::chrono::steady_clock> Clock::GetCurrentTime() const
	{
		return m_Time.CurrentTime;
	}

	std::chrono::time_point<std::chrono::steady_clock> Clock::GetLastTime() const
	{
		return m_Time.LastTime;
	}

	const TimeStep& Clock::GetTimeStep() const
	{
		return m_Time.Timestep;
	}

	uint64_t Clock::GetFrameCount() const
	{
		return m_FrameCount;
	}

	uint16_t Clock::GetFPS() const
	{
		return m_FPS;
	}

	void Clock::Tick()
	{
		m_Time.LastTime = m_Time.CurrentTime;
		m_Time.CurrentTime = std::chrono::high_resolution_clock::now();
		m_Time.Timestep.duration = static_cast<float>(std::chrono::time_point_cast<std::chrono::microseconds>(m_Time.CurrentTime).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(m_Time.LastTime).time_since_epoch().count()) / 1000000.0f;
		m_FPS = static_cast<unsigned short>(1000000.0f / m_Time.Timestep.duration);
		m_FrameCount++;
	}
}