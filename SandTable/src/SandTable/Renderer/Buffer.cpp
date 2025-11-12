/**
 * @file SandTable/Renderer/Buffer.cpp
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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
	ObjectRef<VertexBuffer> VertexBuffer::Create(float* vertices, unsigned int size)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
			return nullptr;
		}
	}

	ObjectRef<IndexBuffer> IndexBuffer::Create(unsigned int* indices, unsigned int count)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return std::make_shared<OpenGLIndexBuffer>(indices, count);
		default:
			return nullptr;
		}
	}
	void BufferLayout::CalculateOffsetAndStride()
	{
		unsigned int offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements)
		{
			element.Offset = offset;
			offset += element.Size;
			m_Stride += element.Size;
		}
	}
}