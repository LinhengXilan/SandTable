/**
 * @file SandTable/Renderer/VertexArray.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
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
			return CreateObjectRef<OpenGLVertexArray>();
		default:
			return nullptr;
		}
	}
}