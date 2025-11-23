/**
 * @file Platform/OpenGL/OpenGLShader.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief OpenGL着色器
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/type_ptr.hpp>
#include <SandTable/Core/Log.h>
#include <SandTable/Core/File.h>
#include <glad/gl.h>


namespace SandTable
{
	static GLenum GetShaderTypeFromString(const std::string& str)
	{
		if (str == "vertex")
		{
			return GL_VERTEX_SHADER;
		}
		if (str == "fragment" || str == "pixel")
		{
			return GL_FRAGMENT_SHADER;
		}
		return NULL;
	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)
		: m_Name(name)
	{
		std::unordered_map<GLenum, std::string> shaderSource;
		shaderSource[GL_VERTEX_SHADER] = vertexSource;
		shaderSource[GL_FRAGMENT_SHADER] = fragmentSource;
		Compile(shaderSource);
		
	}

	OpenGLShader::OpenGLShader(const std::string& path)
	{
		std::string source = File::ReadFile(path, "glsl");
		if (!source.empty()) [[likely]]
		{
			auto shaderSource = Preprocess(source);
			Compile(shaderSource);

			auto lastSlash = path.find_last_of("/\\");
			lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
			auto lastDot = path.find_last_of(".");
			m_Name = path.substr(lastSlash, lastDot - lastSlash);
		}
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::Preprocess(const std::string& source)
	{
		std::unordered_map<GLenum, std::string> shaderSource;

		const std::string typeToken = "#type";
		size_t typeTokenLength = typeToken.size();

		size_t pos = source.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", pos);// 找到#type行结尾
			SANDTABLE_CORE_ASSERT(eol != std::string::npos, "Shader source syntax error");// 若 #type 行后无后续内容，则报错
			// 继续读取
			size_t begin = pos + typeTokenLength + 1; // #type后
			std::string typeStr = source.substr(begin, eol - begin);

			SANDTABLE_CORE_ASSERT(!typeStr.empty(), "Invalid shader type!");

			size_t nextLinePos = source.find_first_not_of("\r\n", eol); // #type下一行
			SANDTABLE_CORE_ASSERT(nextLinePos != std::string::npos, "[Shader: Preprocess] Syntax error");
			pos = source.find(typeToken, nextLinePos); // 下一个#type
			shaderSource[GetShaderTypeFromString(typeStr)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}
		return shaderSource;
	}

	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
	{
		GLuint program = glCreateProgram();
		SANDTABLE_CORE_ASSERT(shaderSources.size() <= 16, "Too much shaders!");
		std::array<GLuint, 6> shaders;
		int shaderIndex = 0;
		for (auto& data : shaderSources)
		{
			GLenum type = data.first;
			const std::string& sourceStr = data.second;
			GLuint shader = glCreateShader(type);
			const GLchar* source = sourceStr.c_str();
			glShaderSource(shader, 1, &source, nullptr);
			glCompileShader(shader);
#ifdef SANDTABLE_DEBUG
			int isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				int maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
				std::string infoLog(maxLength, ' ');
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
				glDeleteShader(shader);
				SANDTABLE_CORE_ERROR("Shader compilation failure!");
				SANDTABLE_CORE_ERROR("{0}", infoLog);
				return;
			}
#endif
			glAttachShader(program, shader);
			shaders[shaderIndex++] = shader;
		}

		glLinkProgram(program);
#ifdef SANDTABLE_DEBUG
		int isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(program, GL_INFO_LOG_LENGTH, &maxLength);
			std::string infoLog(maxLength, ' ');
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
			glDeleteProgram(program);
			for (auto shader : shaders)
			{
				glDeleteShader(shader);
			}
			SANDTABLE_CORE_ERROR("shader link failure!");
			SANDTABLE_CORE_ERROR("{0}", infoLog);
			return;
		}
#endif
		for (auto shader : shaders)
		{
			glDetachShader(program, shader);
			glDeleteShader(shader);
		}
		m_RendererID = program;
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	const std::string& OpenGLShader::GetName() const
	{
		return m_Name;
	}

	/* vvvvv  SetUniform  vvvvv */

	/* vvv  接口  vvv */

	void OpenGLShader::SetData(const std::string& name, const int32_t value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const uint32_t value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const float value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const double value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const glm::vec2& value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const glm::vec3& value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const glm::vec4& value)
	{
		SetUniform(name, value);	
	}

	void OpenGLShader::SetData(const std::string& name, const glm::mat3& value)
	{
		SetUniform(name, value);
	}

	void OpenGLShader::SetData(const std::string& name, const glm::mat4& value)
	{
		SetUniform(name, value);
	}

	/* ^^^  接口  ^^^ */


	void OpenGLShader::SetUniform(const std::string& name, const int32_t value)
	{
		glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void OpenGLShader::SetUniform(const std::string& name, const uint32_t value)
	{
		glUniform1ui(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void OpenGLShader::SetUniform(const std::string& name, const float value)
	{
		glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
	}

	void OpenGLShader::SetUniform(const std::string& name, const double value)
	{
		glUniform1d(glGetUniformLocation(m_RendererID, name.c_str()), value);
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

	void OpenGLShader::SetUniform(const std::string& name, const glm::mat3& value)
	{
		glUniformMatrix3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShader::SetUniform(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	/* ^^^^^  SetUniform  ^^^^^ */
}