/**
 * @file Platform/OpenGL/OpenGLVertexArray.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief OpenGL顶点数组类
 */

#ifndef PLATFORM_OPENGL_OPENGLVERTEXARRAY_H
	#define PLATFORM_OPENGL_OPENGLVERTEXARRAY_H

#include <SandTable/Renderer/VertexArray.h>

namespace SandTable
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray() override;

	public:
		void Bind() const override;
		void Unbind() const override;

		const std::vector<ObjectRef<VertexBuffer>>& GetVertexBuffers() const override;
		const ObjectRef<IndexBuffer>& GetIndexBuffer() const override;

		void AddVertexBuffer(const ObjectRef<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const ObjectRef<IndexBuffer>& indexBuffer) override;

	private:
		std::vector<ObjectRef<VertexBuffer>> m_VertexBuffers;
		uint32_t m_VertexBufferIndex = 0;
		ObjectRef<IndexBuffer> m_IndexBuffer;
		uint32_t m_RendererID;
	};
}

#endif