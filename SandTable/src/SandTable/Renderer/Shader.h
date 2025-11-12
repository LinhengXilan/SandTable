/**
 * @file SandTable/Renderer/Shader.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_SHADER_H
#define SANDTABLE_RENDERER_SHADER_H

#include <SandTable/Core.h>
#include <glm/glm.hpp>

namespace SandTable
{
	class Shader
	{
	public:
		Shader() = default;
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static ObjectRef<Shader> Create(const std::string& vertexSource, std::string& fragmentSource);
	};
}

#endif