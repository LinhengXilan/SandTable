/**
 * @file Platform/OpenGL/OpenGLVertexArray.h
 * @author LinhengXilan
 * @date 2025-10-29
 * @version build21
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
		void Bind() const override;
		void Unbind() const override;
		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override;
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override;
	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		unsigned int m_RendererID;
	};
}

#endif