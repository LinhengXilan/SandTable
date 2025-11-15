/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief 计时器头文件
 */

#ifndef SANDTABLE_CORE_CLOCK_H
#define SANDTABLE_CORE_CLOCK_H

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

		Time(float currentTime)
			: CurrentTime(currentTime), LastTime(currentTime)
		{

		}
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
		const float GetCurrentTime() const;
		const float GetLastTime() const;
		const TimeStep GetTimeStep() const;
		const uint64_t GetFrameCount() const;
		const uint16_t GetFPS() const;

		void Tick();

	private:
		Time m_Time = 0;
		uint64_t m_FrameCount = 0;
		uint16_t m_FPS = 0;
	};
}

#endif