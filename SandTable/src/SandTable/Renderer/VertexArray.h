/**
 * @file SandTable/Renderer/VertexArray.h
 * @author LinhengXilan
 * @date 2025-10-29
 * @version build21
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
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;
		static VertexArray* Create();
	};
}

#endif