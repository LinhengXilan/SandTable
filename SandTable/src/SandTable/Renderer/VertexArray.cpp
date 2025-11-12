/**
 * @file SandTable/Renderer/VertexArray.cpp
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief 着色器类
 */

#include <pch.h>
#include <SandTable/Renderer/VertexArray.h>
#include <SandTable/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace SandTable
{
	ObjectRef<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		default:
			return nullptr;
		}
	}
}