/**
 * @file SandTable/Core/File.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 文件操作
 */

#include <pch.h>
#include <SandTable/Core/File.h>

#include <SandTable/Core/Log.h>

namespace SandTable
{
	/**
	 * @brief 读取文件
	 * @param path 文件路径
	 * @return 读取的字符串
	 */
	std::string File::ReadFile(const std::string& path)
	{
		std::ifstream ifs(path, std::ios::in | std::ios::binary);
		if (ifs) [[likely]]
		{
			std::string str;
			ifs.seekg(0, std::ios::end);
			str.resize(ifs.tellg());
			ifs.seekg(0, std::ios::beg);
			ifs.read(&str[0], str.size());
			ifs.close();
			return str;
		}
		SANDTABLE_CORE_WARN("[Shader] Could not to open file \"{0}\"", path);
		return "";
	}

	/**
	 * @brief 读取特定后缀的文件
	 * @param path 文件路径
	 * @param postfix 文件后缀
	 * @return 读取的字符串
	 * @note Debug模式下后缀不符时报错
	 */
	std::string File::ReadFile(const std::string& path, const std::string& postfix)
	{
#ifdef SANDTABLE_DEBUG
		auto pathPostfixPos = path.find_last_of('.') + 1;
		if (pathPostfixPos == std::string::npos || path.substr(pathPostfixPos, path.size() - pathPostfixPos) != postfix)
		{
			SANDTABLE_CORE_WARN("[File] Wrong file type: \"{0}\"", path);
			return "";
		}
#endif
		std::ifstream ifs(path, std::ios::in | std::ios::binary);
		if (ifs) [[likely]]
		{
			std::string str;
			ifs.seekg(0, std::ios::end);
			str.resize(ifs.tellg());
			ifs.seekg(0, std::ios::beg);
			ifs.read(&str[0], str.size());
			ifs.close();
			return str;
		}
		SANDTABLE_CORE_WARN("[File] Could not open file: \"{0}\"", path);
		return "";
	}
}