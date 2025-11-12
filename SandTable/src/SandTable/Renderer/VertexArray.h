/**
 * @file SandTable/Renderer/VertexArray.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief 顶点数组接口
 */

#ifndef SANDTABLE_RENDERER_VERTEXARRAY_H
	#define SANDTABLE_RENDERER_VERTEXARRAY_H

#include <SandTable/Renderer/Buffer.h>

namespace SandTable
{
	class VertexArray
	{
	public:
		VertexArray() = default;
		virtual ~VertexArray() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const ObjectRef<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const ObjectRef<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<ObjectRef<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const ObjectRef<IndexBuffer>& GetIndexBuffer() const = 0;
		static ObjectRef<VertexArray> Create();
	};
}

#endif