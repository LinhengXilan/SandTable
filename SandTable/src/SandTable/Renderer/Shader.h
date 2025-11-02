/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_SHADER_H
	#define SANDTABLE_RENDERER_SHADER_H

#include <glm/glm.hpp>

namespace SandTable
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void Bind() const;
		void Unbind() const;
			
		void SetUniform(const std::string& name, const glm::mat4& value);


	private:
		unsigned int m_RendererID;
	};
}

#endif