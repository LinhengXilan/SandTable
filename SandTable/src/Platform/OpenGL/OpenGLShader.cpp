/**
 * @file Platform/OpenGL/OpenGLShader.cpp
 * @author LinhengXilan
 * @date 2025-11-9
 * @version build27
 * 
 * @brief OpenGL着色器
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glad/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include <SandTable/Log.h>

namespace SandTable
{
	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
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

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	/* vvv  SetUniform  vvv */

	/* vvv  int  vvv */

	void OpenGLShader::SetUniform(const std::string& name, const int value)
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	/* vvv  vector(float)  vvv */

	void OpenGLShader::SetUniform(const std::string& name, const float value)
	{
		glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void OpenGLShader::SetUniform(const std::string& name, const glm::vec2& value)
	{
		glUniform2f(glGetUniformLocation(m_RendererID, name.c_str()), value.x, value.y);
	}

	void OpenGLShader::SetUniform(const std::string& name, const glm::vec3& value)
	{
		glUniform3f(glGetUniformLocation(m_RendererID, name.c_str()), value.x, value.y, value.z);
	}

	void OpenGLShader::SetUniform(const std::string& name, const glm::vec4& value)
	{
		glUniform4f(glGetUniformLocation(m_RendererID, name.c_str()), value.x, value.y, value.z, value.w);
	}

	/* ^^^  vector(float)  ^^^ */

	/* vvv  matrix  vvv */

	void OpenGLShader::SetUniform(const std::string& name, const glm::mat3& value)
	{
		glUniformMatrix3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShader::SetUniform(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	/* ^^^  matrix  ^^^ */

	/* ^^^  SetUniform  ^^^ */
}