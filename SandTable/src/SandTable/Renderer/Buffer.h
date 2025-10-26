/**
 * @file SandTable/Renderer/Buffer.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief 渲染缓冲头文件
 */

#ifndef SANDTABLE_RENDERER_BUFFER_H
	#define SANDTABLE_RENDERER_BUFFER_H

namespace SandTable
{
	class VertexBuffer
	{
	public:
		//virtual ~VertexBuffer();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static VertexBuffer* Create(float* vertices, unsigned int size);
	};

	class IndexBuffer
	{
	public:
		//virtual ~IndexBuffer();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual unsigned int GetCount() const = 0;

		static IndexBuffer* Create(unsigned int* indices, unsigned int count);
	};


}

#endif