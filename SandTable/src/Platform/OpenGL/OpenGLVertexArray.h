/**
 * @file Platform/OpenGL/OpenGLVertexArray.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
		~OpenGLVertexArray();

	public:
		void Bind() const override;
		void Unbind() const override;

		const std::vector<ObjectRef<VertexBuffer>>& GetVertexBuffers() const override;
		const ObjectRef<IndexBuffer>& GetIndexBuffer() const override;

		void AddVertexBuffer(const ObjectRef<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const ObjectRef<IndexBuffer>& indexBuffer) override;

	private:
		std::vector<ObjectRef<VertexBuffer>> m_VertexBuffers;
		ObjectRef<IndexBuffer> m_IndexBuffer;
		unsigned int m_RendererID;
	};
}

#endif