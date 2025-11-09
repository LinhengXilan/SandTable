/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @date 2025-11-9
 * @version build27
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
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Shader* Create(const std::string& vertexSource, std::string& fragmentSource);
	};
}

#endif