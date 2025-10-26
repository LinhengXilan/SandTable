/**
 * @file Platform/OpenGL/OpenGLContext.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief OpenGL图形上下文头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLCONTEXT_H
	#define PLATFORM_OPENGL_OPENGLCONTEXT_H

#include <SandTable/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace SandTable
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}

#endif