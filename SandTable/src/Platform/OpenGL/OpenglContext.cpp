/**
 * @file Platform/OpenGL/OpenGLContext.cpp
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief OpenGL图形上下文实现
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLContext.h>
#include <glad/gl.h>
#include <glfw/glfw.h>
#include <SandTable/Core.h>
#include <SandTable/Log.h>

namespace SandTable
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SANDTABLE_CORE_ASSERT(windowHandle, "WindowHandle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
		SANDTABLE_CORE_ASSERT(status, "Failed to initialize glad!");

		SANDTABLE_CORE_INFO("OpenGL Info:");
		SANDTABLE_CORE_INFO(" - Vendor: {0}", (char*)glGetString(GL_VENDOR));
		SANDTABLE_CORE_INFO(" - Renderer: {0}", (char*)glGetString(GL_RENDERER));
		SANDTABLE_CORE_INFO(" - Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}