/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 时钟
 */

#ifndef SANDTABLE_CORE_CLOCK_H
#define SANDTABLE_CORE_CLOCK_H

#include <SandTable/Core/Core.h>

#pragma warning(disable:4244)

namespace SandTable
{
	/**
	 * @brief 时间长度
	 */
	struct TimeStep
	{
		float duration = 0.0f;
	};

	/**
	 * @brief 时间
	 */
	struct Time
	{
		std::chrono::time_point<std::chrono::steady_clock> CurrentTime;
		std::chrono::time_point<std::chrono::steady_clock> LastTime;
		TimeStep Timestep = {0.0f};

		Time() = default;
		Time(std::chrono::time_point<std::chrono::steady_clock> time);
	};

	/**
	 * @brief 时钟
	 */
	class Clock
	{
	public:
		Clock();
		~Clock() = default;

	public:
		std::chrono::time_point<std::chrono::steady_clock> GetCurrentTime() const;
		std::chrono::time_point<std::chrono::steady_clock> GetLastTime() const;
		const TimeStep& GetTimeStep() const;
		uint64_t GetFrameCount() const;
		uint16_t GetFPS() const;

		void Tick();

	private:
		Time m_Time;
		uint64_t m_FrameCount = 0;
		uint16_t m_FPS = 0;
	};
}

#endif