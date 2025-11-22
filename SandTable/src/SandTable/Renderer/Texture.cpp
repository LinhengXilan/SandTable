/**
 * @file SandTable/Renderer/Texture.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 纹理
 */

#include <pch.h>
#include <SandTable/Renderer/Texture.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLTexture.h>

namespace SandTable
{
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

}