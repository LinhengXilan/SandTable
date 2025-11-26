/**
 * @file SandTable/Core.h
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief SandTable核心头文件
 */

#ifndef SANDTABLE_CORE_H
#define SANDTABLE_CORE_H

#include <memory>

#ifdef SANDTABLE_BUILD_DLL
	#define SANDTABLE_DLL //__declspec(dllexport)
#else
	#define SANDTABLE_DLL //__declspec(dllimport)
#endif
#ifdef _WIN32
	#ifdef _WIN64
		#define SANDTABLE_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define SANDTABLE_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define SANDTABLE_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#define SANDTABLE_DLL __declspec(dllimport)
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define SANDTABLE_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define SANDTABLE_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	#define SANDTABLE_DLL
#endif

#ifdef SANDTABLE_DEBUG
	#define SANDTABLE_ENABLE_ASSERTS
#endif

/* vvv 标志 vvv */

#define PRIVATE	// 用于标记private成员函数

/* ^^^ 标志 ^^^ */
/* vvv 辅助宏函数 vvv */

#define BIT(x) (1 << x)
#define SANDTABLE_BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

/* ^^^ 辅助宏函数 ^^^ */
/* vvv 别名 vvv */

namespace SandTable
{
	template<typename T>
	using ObjectRef = std::shared_ptr<T>;

	template<typename T, typename... Args>
	constexpr ObjectRef<T> CreateObjectRef(Args&&... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}


	template<typename T>
	using Object = std::unique_ptr<T>;

	template<typename T, typename... Args>
	constexpr Object<T> CreateObject(Args&&... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}

/* ^^^ 别名 ^^^ */

#endif