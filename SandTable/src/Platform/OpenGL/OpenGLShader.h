/**
 * @file Platform/OpenGL/OpenGLShader.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief OpenGL着色器
 */

#ifndef PLATFORM_OPENGL_OPENGLSHADER_H
#define PLATFORM_OPENGL_OPENGLSHADER_H

#include <SandTable/Renderer/Shader.h>
#include <glm/glm.hpp>

// TODO: 移除该类型别名
typedef unsigned int GLenum;

namespace SandTable
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);
		OpenGLShader(const std::string& path);
		~OpenGLShader();

	public:
		void Bind() const override;
		void Unbind() const override;

		const std::string& GetName() const override;

		void SetUniform(const std::string& name, const int32_t value);
		void SetUniform(const std::string& name, const uint32_t value);
		void SetUniform(const std::string& name, const float value);
		void SetUniform(const std::string& name, const glm::vec2& value);
		void SetUniform(const std::string& name, const glm::vec3& value);
		void SetUniform(const std::string& name, const glm::vec4& value);
		void SetUniform(const std::string& name, const glm::mat3& value);
		void SetUniform(const std::string& name, const glm::mat4& value);

	private:
		std::unordered_map<GLenum, std::string> Preprocess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSource);

	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
}

#endif