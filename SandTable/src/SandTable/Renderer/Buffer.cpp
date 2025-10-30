/**
 * @file SandTable/Renderer/Buffer.cpp
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief 渲染缓冲实现
 */

#include <pch.h>
#include <SandTable/Renderer/Buffer.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Log.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace SandTable
{
	VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
		case RendererAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}

}