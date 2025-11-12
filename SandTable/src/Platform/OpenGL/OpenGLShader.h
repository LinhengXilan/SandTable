/**
 * @file Platform/OpenGL/OpenGLShader.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief OpenGL着色器
 */

#ifndef PLATFORM_OPENGL_OPENGLSHADER_H
#define PLATFORM_OPENGL_OPENGLSHADER_H

#include <SandTable/Renderer/Shader.h>
#include <glm/glm.hpp>

namespace SandTable
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGLShader();

	public:
		void Bind() const override;
		void Unbind() const override;

		void SetUniform(const std::string& name, const int32_t value);
		void SetUniform(const std::string& name, const uint32_t value);
		void SetUniform(const std::string& name, const float value);
		void SetUniform(const std::string& name, const glm::vec2& value);
		void SetUniform(const std::string& name, const glm::vec3& value);
		void SetUniform(const std::string& name, const glm::vec4& value);
		void SetUniform(const std::string& name, const glm::mat3& value);
		void SetUniform(const std::string& name, const glm::mat4& value);
		
	private:
		uint32_t m_RendererID;
	};
}

#endif