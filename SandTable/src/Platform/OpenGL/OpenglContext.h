/**
 * @file Platform/OpenGL/OpenGLContext.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief OpenGL图形上下文头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLCONTEXT_H
#define PLATFORM_OPENGL_OPENGLCONTEXT_H

#include <SandTable/Core/Core.h>
#include <SandTable/Renderer/GraphicsContext.h>

struct GLFWwindow;

namespace SandTable
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);
		~OpenGLContext() override = default;

	public:
		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}

#endif