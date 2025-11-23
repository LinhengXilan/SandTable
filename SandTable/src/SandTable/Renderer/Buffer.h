/**
 * @file SandTable/Renderer/Buffer.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 渲染缓冲头文件
 */

#ifndef SANDTABLE_RENDERER_BUFFER_H
	#define SANDTABLE_RENDERER_BUFFER_H

#include <SandTable/Core/Log.h>

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
	static unsigned int GetShaderDataTypeSize(ShaderDataType type);
	 
	/**
	 * @brief 缓冲元素结构体
	 */
	struct BufferElement
	{
		ShaderDataType Type; /// 着色器数据类型
		std::string Name;	 /// 元素名称
		uint32_t Size;	 /// 元素大小
		size_t Offset; /// 元素偏移
		bool Normalized;	 /// 是否归一化

		BufferElement() = default;
		BufferElement(ShaderDataType type = ShaderDataType::None, const std::string& name = "", bool normalized = false);

		/**
		 * @brief 获取组件数量
		 * @return unsigned int 组件数量
		 */
		uint8_t GetComponentCount() const;
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElement>& elements);
		~BufferLayout() = default;

	public:
		const std::vector<BufferElement>& GetElements() const;
		uint8_t GetStride() const;

		std::vector<BufferElement>::iterator begin();
		std::vector<BufferElement>::iterator end();
		std::vector<BufferElement>::const_iterator cbegin() const;
		std::vector<BufferElement>::const_iterator cend() const;

	private:
		void CalculateOffsetAndStride();

	private:
		std::vector<BufferElement> m_Elements;
		uint8_t m_Stride = 0;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		virtual ~VertexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		static ObjectRef<VertexBuffer> Create(float* vertices, int32_t size);
	};

	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		virtual ~IndexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual const int32_t GetCount() const = 0;

		static ObjectRef<IndexBuffer> Create(uint32_t* indices, int32_t count);
	};


}

#endif