/**
 * @file Platform/OpenGL/OpenGLShader.h
 * @author LinhengXilan
 * @date 2025-11-9
 * @version build27
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

		void Bind() const override;
		void Unbind() const override;

		void SetUniform(const std::string& name, const int value);

		void SetUniform(const std::string& name, const float value);
		void SetUniform(const std::string& name, const glm::vec2& value);
		void SetUniform(const std::string& name, const glm::vec3& value);
		void SetUniform(const std::string& name, const glm::vec4& value);

		void SetUniform(const std::string& name, const glm::mat3& value);
		void SetUniform(const std::string& name, const glm::mat4& value);
		

	private:
		unsigned int m_RendererID;
	};
}

#endif