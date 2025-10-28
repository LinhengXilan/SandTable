/**
 * @file SandTable/Renderer/Buffer.h
 * @author LinhengXilan
 * @date 2025-10-28
 * @version build20
 * 
 * @brief 渲染缓冲头文件
 */

#ifndef SANDTABLE_RENDERER_BUFFER_H
	#define SANDTABLE_RENDERER_BUFFER_H

#include <SandTable/Log.h>

namespace SandTable
{
	/**
	 * @brief 着色器数据类型枚举
	 */
	enum class ShaderDataType : unsigned char
	{
		None = 0,
		Float = 0x10,	Float2, Float3, Float4,
		Matrix3 = 0x20, Matrix4,
		Int = 0x30,		Int2, Int3, Int4,
		Bool = 0x40
	};

	/**
	 * @param type 着色器数据类型
	 * @return unsigned int 着色器数据类型大小（字节）
	 * @brief 获取着色器数据类型大小
	 */
	static unsigned int GetShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return 4;
		case ShaderDataType::Float2:   return 4 * 2;
		case ShaderDataType::Float3:   return 4 * 3;
		case ShaderDataType::Float4:   return 4 * 4;
		case ShaderDataType::Matrix3:  return 4 * 3 * 3;
		case ShaderDataType::Matrix4:  return 4 * 4 * 4;
		case ShaderDataType::Int:      return 4;
		case ShaderDataType::Int2:     return 4 * 2;
		case ShaderDataType::Int3:     return 4 * 3;
		case ShaderDataType::Int4:     return 4 * 4;
		case ShaderDataType::Bool:     return 1;
		default:
			SANDTABLE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		}
		return 0;
	}
	 
	/**
	 * @brief 缓冲元素结构体
	 */
	struct BufferElement
	{
		ShaderDataType Type; /// 着色器数据类型
		std::string Name;	 /// 元素名称
		unsigned int Size;	 /// 元素大小
		unsigned int Offset; /// 元素偏移
		bool Normalized;	 /// 是否归一化

		BufferElement() = default;
		BufferElement(ShaderDataType type = ShaderDataType::None, const std::string& name = "", bool normalized = false)
			: Type(type), Name(name), Size(GetShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
		{

		}

		/**
		 * @brief 获取组件数量
		 * @return unsigned int 组件数量
		 */
		unsigned int GetComponentCount() const
		{
			switch (Type)
			{
			case ShaderDataType::Float:    return 1;
			case ShaderDataType::Float2:   return 2;
			case ShaderDataType::Float3:   return 3;
			case ShaderDataType::Float4:   return 4;
			case ShaderDataType::Matrix3:  return 3 * 3;
			case ShaderDataType::Matrix4:  return 4 * 4;
			case ShaderDataType::Int:      return 1;
			case ShaderDataType::Int2:     return 2;
			case ShaderDataType::Int3:     return 3;
			case ShaderDataType::Int4:     return 4;
			case ShaderDataType::Bool:     return 1;
			default:
				SANDTABLE_CORE_ASSERT(false, "Unknown ShaderDataType!");
			}
			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElement>& elements)
			: m_Elements(elements)
		{
			CalculateOffsetAndStride();
		}

		~BufferLayout() = default;
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const { return m_Stride; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.cbegin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.cend(); }

	private:
		/**
		 * @brief 计算偏移和步长
		 */
		void CalculateOffsetAndStride()
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

	private:
		std::vector<BufferElement> m_Elements;
		unsigned int m_Stride = 0;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

		static VertexBuffer* Create(float* vertices, unsigned int size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual unsigned int GetCount() const = 0;

		static IndexBuffer* Create(unsigned int* indices, unsigned int count);
	};


}

#endif