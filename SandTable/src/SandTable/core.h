/**
 * @file SandTable/Core.h
 * @author LinhengXilan
 * @version build31
 * @date 2025-11-15
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

#define BIT(x) (1 << x)
#define SANDTABLE_BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

namespace SandTable
{
	template<typename T>
	using ObjectRef = std::shared_ptr<T>;

	template<typename T>
	using Object = std::unique_ptr<T>;
}

#endif