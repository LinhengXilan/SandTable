/**
 * @file SandTable/Renderer/Buffer.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 渲染缓冲实现
 */

#include <pch.h>
#include <SandTable/Renderer/Buffer.h>
#include <SandTable/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace SandTable
{
	ObjectRef<VertexBuffer> VertexBuffer::Create(float* vertices, int32_t size)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLVertexBuffer>(vertices, size);
		default:
			return nullptr;
		}
	}

	ObjectRef<IndexBuffer> IndexBuffer::Create(uint32_t* indices, int32_t count)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObjectRef<OpenGLIndexBuffer>(indices, count);
		default:
			return nullptr;
		}
	}

	const std::vector<BufferElement>& BufferLayout::GetElements() const
	{
		return m_Elements;
	}

	uint8_t BufferLayout::GetStride() const
	{
		return m_Stride;
	}

	std::vector<BufferElement>::iterator BufferLayout::begin()
	{
		return m_Elements.begin();
	}

	std::vector<BufferElement>::iterator BufferLayout::end()
	{
		return m_Elements.end();
	}

	std::vector<BufferElement>::const_iterator BufferLayout::cbegin() const
	{
		return m_Elements.cbegin();
	}

	std::vector<BufferElement>::const_iterator BufferLayout::cend() const
	{
		return m_Elements.cend();
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