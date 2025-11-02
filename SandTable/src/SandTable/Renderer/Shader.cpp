/**
 * @file SandTable/Renderer/Shader.cpp
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief 着色器类实现
 */

#include <pch.h>
#include <SandTable/Renderer/Shader.h>
#include <glad/gl.h>
#include <SandTable/Log.h>
#include <glm/gtc/type_ptr.hpp>

namespace SandTable
{
	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		// vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* source = vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, nullptr);
		glCompileShader(vertexShader);
#ifdef SANDTABLE_DEBUG
		int isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);
			std::string infoLog(maxLength, ' ');
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);
			glDeleteShader(vertexShader);
			SANDTABLE_CORE_ERROR("Vertex shader compilation failure!");
			SANDTABLE_CORE_ERROR("{0}", infoLog);
			return;
		}
#endif
		m_RendererID = glCreateProgram();
		glAttachShader(m_RendererID, vertexShader);

		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		source = fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, nullptr);
		glCompileShader(fragmentShader);

#ifdef SANDTABLE_DEBUG
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
			std::string infoLog(maxLength, ' ');
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);
			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);
			SANDTABLE_CORE_ERROR("Fragment shader compilation failure!");
			SANDTABLE_CORE_ERROR("{0}", infoLog);
			return;
		}
#endif

		glAttachShader(m_RendererID, fragmentShader);
		glLinkProgram(m_RendererID);

#ifdef SANDTABLE_DEBUG
		int isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
			std::string infoLog(maxLength, ' ');
			glGetProgramInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);
			glDeleteProgram(m_RendererID);
			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);
			SANDTABLE_CORE_ERROR("shader link failure!");
			SANDTABLE_CORE_ERROR("{0}", infoLog);
			return;
		}
#endif

		glDetachShader(m_RendererID, vertexShader);
		glDetachShader(m_RendererID, fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}
	
	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}
}