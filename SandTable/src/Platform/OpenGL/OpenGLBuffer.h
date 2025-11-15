/**
 * @file Platform/OpenGL/OpenGLBuffer.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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

	public:
		void Bind() const override;
		void Unbind() const override;

		const BufferLayout& GetLayout() const override;
		void SetLayout(const BufferLayout& layout) override;

	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
		~OpenGLIndexBuffer();

	public:
		void Bind() const override;
		void Unbind() const override;
		const uint32_t GetCount() const override;

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}

#endif