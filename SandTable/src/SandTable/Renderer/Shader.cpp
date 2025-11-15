/**
 * @file SandTable/Renderer/Shader.cpp
 * @author LinhengXilan
 * @version build31
 * @date 2025-11-15
 * 
 * @brief 着色器类实现
 */

#include <pch.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLShader.h>

namespace SandTable
{
	ObjectRef<Shader> Shader::Create(const std::string& vertexSource, std::string& fragmentSource)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return std::make_shared<OpenGLShader>(vertexSource, fragmentSource);
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
			return std::make_shared<OpenGLShader>(path);
		default:
			return nullptr;
		}
	}
}