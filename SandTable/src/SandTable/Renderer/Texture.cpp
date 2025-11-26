/**
 * @file SandTable/Renderer/Texture.cpp
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 纹理
 */

#include <pch.h>
#include <SandTable/Renderer/Texture.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLTexture.h>

namespace SandTable
{
	ObjectRef<Texture2D> Texture2D::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLTexture2D>();
		default:
			return nullptr;
		}
	}

	ObjectRef<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLTexture2D>(path);
		default:
			return nullptr;
		}
	}

	ObjectRef<Texture2D> Texture2D::Create(int32_t width, int32_t height)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLTexture2D>(width, height);
		default:
			return nullptr;
		}
	}
}