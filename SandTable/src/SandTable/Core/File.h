/**
 * @file SandTable/Core/File.h
 * @author LinhengXilan
 * @version build31
 * @date 2025-11-15
 * 
 * @brief 文件操作
 */

#ifndef SANDTABLE_CORE_FILE_H
#define SANDTABLE_CORE_FILE_H

namespace SandTable
{
	class File
	{
	public:
		File() = default;
		~File() = default;

		static std::string ReadFile(const std::string& path);
	};
}

#endif