/**
 * @file SandTable/Core/Clock.cpp
 * @author LinhengXilan
 * @date 2025-11-7
 * @version build25
 * 
 * @brief 计时器实现
 */

#include <pch.h>
#include <SandTable/Core/Clock.h>
#include <glfw/glfw.h>

namespace SandTable
{
	Clock::Clock()
		: m_Time(glfwGetTime()), m_FrameCount(0)
	{

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