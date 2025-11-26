/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 计时器头文件
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
		float CurrentTime = 0.0f;
		float LastTime = 0.0f;
		TimeStep Timestep;

		Time() = default;
		Time(float currentTime);
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
		float GetCurrentTime() const;
		float GetLastTime() const;
		const TimeStep& GetTimeStep() const;
		uint64_t GetFrameCount() const;
		uint16_t GetFPS() const;

		void Tick();

	private:
		Time m_Time = 0;
		uint64_t m_FrameCount = 0;
		uint16_t m_FPS = 0;
	};
}

#endif