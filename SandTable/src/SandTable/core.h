/**
 * @file SandTable/Core.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief SandTable核心头文件
 */

#ifndef SANDTABLE_CORE_H
#define SANDTABLE_CORE_H

#ifdef SANDTABLE_PLATFORM_WINDOWS
	#ifdef SANDTABLE_BUILD_DLL
		#define SANDTABLE_DLL //__declspec(dllexport)
	#else
		#define SANDTABLE_DLL //__declspec(dllimport)
	#endif
#else
	#define SANDTABLE_DLL
	#error SandTable only supports Windows
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

	template<typename T>
	using Object = std::unique_ptr<T>;
}

/* ^^^ 别名 ^^^ */

#endif