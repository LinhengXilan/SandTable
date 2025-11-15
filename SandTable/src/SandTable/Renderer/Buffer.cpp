/**
 * @file SandTable/Renderer/Buffer.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		default:
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