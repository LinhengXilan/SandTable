/**
 * @file SandTable/Renderer/VertexArray.cpp
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief 着色器类
 */

#include <pch.h>
#include <SandTable/Renderer/VertexArray.h>
#include <SandTable/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace SandTable
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}
}