/**
 * @file Platform/OpenGL/OpenGLContext.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief OpenGL图形上下文头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLCONTEXT_H
#define PLATFORM_OPENGL_OPENGLCONTEXT_H

#include <SandTable/Core.h>
#include <SandTable/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace SandTable
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(ObjectRef<GLFWwindow> window);
		~OpenGLContext() = default;

	public:
		void Init() override;
		void SwapBuffers() override;

	private:
		ObjectRef<GLFWwindow> m_WindowHandle;
	};
}

#endif