/**
 * @file SandTable/Renderer/Shader.cpp
 * @author LinhengXilan
 * @date 2025-11-9
 * @version build27
 * 
 * @brief 着色器类实现
 */

#include <pch.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLShader.h>

namespace SandTable
{
	Shader* Shader::Create(const std::string& vertexSource, std::string& fragmentSource)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return new OpenGLShader(vertexSource, fragmentSource);
		default:
			return nullptr;
		}
	}

}