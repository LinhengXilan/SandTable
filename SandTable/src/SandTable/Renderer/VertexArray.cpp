/**
 * @file SandTable/Renderer/VertexArray.cpp
 * @author LinhengXilan
 * @date 2025-10-29
 * @version build21
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
		case RendererAPI::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}
}