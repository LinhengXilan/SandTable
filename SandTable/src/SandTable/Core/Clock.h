/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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
		double duration;
		operator float() { return duration; }
	};

	/**
	 * @brief 时间
	 */
	struct Time
	{
		double CurrentTime;
		double LastTime;
		TimeStep Timestep;

		Time()
			: CurrentTime(0.0), LastTime(0.0), Timestep(0.0)
		{ 

		}

		Time(double currentTime)
			: CurrentTime(currentTime), LastTime(currentTime), Timestep(0.0)
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
		inline const double GetCurrentTime() const { return m_Time.CurrentTime; }
		inline const double GetLastTime() const { return m_Time.LastTime; }
		inline const TimeStep GetTimeStep() const { return m_Time.Timestep; }
		inline const uint64_t GetFrameCount() const { return m_FrameCount; }
		inline const uint16_t GetFPS() const { return m_FPS; }

		void Tick();

	private:
		Time m_Time;
		uint64_t m_FrameCount;
		uint16_t m_FPS;
	};
}

#endif