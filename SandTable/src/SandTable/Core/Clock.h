/**
 * @file SandTable/Core/Clock.h
 * @author LinhengXilan
 * @date 2025-11-7
 * @version build25
 * 
 * @brief 计时器头文件
 */

#ifndef SANDTABLE_CORE_CLOCK_H
#define SANDTABLE_CORE_CLOCK_H

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
			: CurrentTime(0.0), LastTime(0.0), Timestep{0.0}
		{ 

		}

		Time(double currentTime)
			: CurrentTime(currentTime), LastTime(currentTime), Timestep{0.0}
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

		inline double GetCurrentTime() const { return m_Time.CurrentTime; }
		inline double GetLastTime() const { return m_Time.LastTime; }
		inline TimeStep GetTimeStep() const { return m_Time.Timestep; }
		inline unsigned long long GetFrameCount() const { return m_FrameCount; }
		inline unsigned short GetFPS() const { return m_FPS; }

		void Tick();

	private:
		Time m_Time;
		unsigned long long m_FrameCount;
		unsigned short m_FPS;
	};
}

#endif