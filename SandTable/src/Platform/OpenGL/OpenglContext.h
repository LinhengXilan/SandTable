/**
 * @file Platform/OpenGL/OpenglContext.h
 * @author LinhengXilan
 * @date 2025-10-24
 * @version build16
 * 
 * @brief OpenGL图形上下文头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLCONTEXT_H
	#define PLATFORM_OPENGL_OPENGLCONTEXT_H

#include <glfw/glfw.h>

#include <SandTable/Renderer/GraphicsContext.h>

namespace SandTable
{
	class OpenglContext : public GraphicsContext
	{
	public:
		OpenglContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}

#endif