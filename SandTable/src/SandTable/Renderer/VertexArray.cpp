/**
 * @file SandTable/Renderer/VertexArray.cpp
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
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
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();
		default:
			return nullptr;
		}
	}
}