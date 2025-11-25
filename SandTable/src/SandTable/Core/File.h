/**
 * @file SandTable/Core/File.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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
		File() = delete;
		~File() = delete;

		static std::string ReadFile(const std::string& path);
		static std::string ReadFile(const std::string& path, const std::string& postfix);
	};
}

#endif