/**
 * @file SandTable/Core/File.cpp
 * @author LinhengXilan
 * @version build31
 * @date 2025-11-15
 * 
 * @brief 文件操作
 */

#include <pch.h>
#include <SandTable/Core/File.h>

#include <SandTable/Log.h>

namespace SandTable
{
	std::string File::ReadFile(const std::string& path)
	{
		std::ifstream ifs(path, std::ios::in, std::ios::binary);
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
}