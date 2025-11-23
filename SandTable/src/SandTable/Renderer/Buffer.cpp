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

	/**
	 * @param type 着色器数据类型
	 * @return unsigned int 着色器数据类型大小（字节）
	 * @brief 获取着色器数据类型大小
	 */
	static unsigned int GetShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:		return 4;
		case ShaderDataType::Float2:	return 4 * 2;
		case ShaderDataType::Float3:	return 4 * 3;
		case ShaderDataType::Float4:	return 4 * 4;
		case ShaderDataType::Matrix3:	return 4 * 3 * 3;
		case ShaderDataType::Matrix4:	return 4 * 4 * 4;
		case ShaderDataType::Int:		return 4;
		case ShaderDataType::Int2:		return 4 * 2;
		case ShaderDataType::Int3:		return 4 * 3;
		case ShaderDataType::Int4:		return 4 * 4;
		case ShaderDataType::Bool:		return 1;
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}
	}

	BufferElement::BufferElement(ShaderDataType type, const std::string& name, bool normalized)
		: Type(type), Name(name), Size(GetShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
	{

	}

	uint8_t BufferElement::GetComponentCount() const
	{
		switch (Type)
		{
		case ShaderDataType::Float:		return 1;
		case ShaderDataType::Float2:	return 2;
		case ShaderDataType::Float3:	return 3;
		case ShaderDataType::Float4:	return 4;
		case ShaderDataType::Matrix3:	return 3 * 3;
		case ShaderDataType::Matrix4:	return 4 * 4;
		case ShaderDataType::Int:		return 1;
		case ShaderDataType::Int2:		return 2;
		case ShaderDataType::Int3:		return 3;
		case ShaderDataType::Int4:		return 4;
		case ShaderDataType::Bool:		return 1;
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown ShaderDataType!");
			return 0;
		}
	}

	BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements)
		: m_Elements(elements)
	{
		CalculateOffsetAndStride();
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
		size_t offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elements)
		{
			element.Offset = offset;
			offset += element.Size;
			m_Stride += element.Size;
		}
	}
}