/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build18
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_SHADER_H
	#define SANDTABLE_RENDERER_SHADER_H

#include <string>

namespace SandTable
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int m_RendererID;
	};
}

#endif