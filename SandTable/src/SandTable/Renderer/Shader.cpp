/**
 * @file SandTable/Renderer/Shader.cpp
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 着色器类实现
 */

#include <pch.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLShader.h>

namespace SandTable
{
	ObjectRef<Shader> Shader::Create(const std::string& name, const std::string& vertexSource, std::string& fragmentSource)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLShader>(name, vertexSource, fragmentSource);
		default:
			return nullptr;
		}
	}

	ObjectRef<Shader> Shader::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLShader>(path);
		default:
			return nullptr;
		}
	}

	const ObjectRef<Shader>& ShaderLibrary::GetShader(const std::string& name)
	{
		SANDTABLE_CORE_ASSERT(m_Shaders.find(name) != m_Shaders.end(), "Shader not found!");
		return m_Shaders[name];
	}

	void ShaderLibrary::Add(const ObjectRef<Shader>& shader)
	{
		ShaderLibrary::Add(shader->GetName(), shader);
	}

	void ShaderLibrary::Add(const std::string& name, const ObjectRef<Shader>& shader)
	{
		SANDTABLE_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end(), "Shader already exists!");
		m_Shaders[name] = shader;
	}

	ObjectRef<Shader> ShaderLibrary::Load(const std::string& path)
	{
		auto shader = Shader::Create(path);
		Add(shader);
		return shader;
	}

	ObjectRef<Shader> ShaderLibrary::Load(const std::string& name, const std::string& path)
	{
		auto shader = Shader::Create(path);
		Add(name, shader);
		return shader;
	}
}