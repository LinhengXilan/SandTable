/**
 * @file Core.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build5
 */

#ifndef CORE_H
#define CORE_H

#ifdef SANDTABLE_PLATFORM_WINDOWS
	#ifdef SANDTABLE_BUILD_DLL
		#define SANDTABLE_DLL __declspec(dllexport)
	#else
		#define SANDTABLE_DLL __declspec(dllimport)
	#endif
#else
	#error SandTable only supports Windows
#endif

#define BIT(x) (1 << x)

#endif