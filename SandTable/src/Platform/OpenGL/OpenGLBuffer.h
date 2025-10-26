/**
 * @file Platform/OpenGL/OpenGLBuffer.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief OpenGL图形缓冲头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLBUFFER_H
	#define PLATFORM_OPENGL_OPENGLBUFFER_H

#include <SandTable/Renderer/Buffer.h>

namespace SandTable
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, unsigned int size);
		~OpenGLVertexBuffer();
		void Bind() const override;
		void Unbind() const override;

	private:
		unsigned int m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
		~OpenGLIndexBuffer();
		void Bind() const override;
		void Unbind() const override;
		inline unsigned int GetCount() const override { return m_Count; }

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	};
}

#endif