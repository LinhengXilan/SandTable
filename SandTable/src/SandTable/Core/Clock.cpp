/**
 * @file SandTable/Core/Clock.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 计时器实现
 */

#include <pch.h>
#include <SandTable/Core/Clock.h>
#include <glfw/glfw.h>

namespace SandTable
{

	Time::Time(float currentTime)
		: CurrentTime(currentTime), LastTime(currentTime)
	{

	}

	Clock::Clock()
		: m_Time(glfwGetTime())
	{

	}

	float Clock::GetCurrentTime() const
	{
		return m_Time.CurrentTime;
	}

	float Clock::GetLastTime() const
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
		m_Time.CurrentTime = glfwGetTime();
		m_Time.Timestep.duration = m_Time.CurrentTime - m_Time.LastTime;
		m_FPS = static_cast<unsigned short>(1.0 / m_Time.Timestep.duration);
		m_FrameCount++;
	}
}