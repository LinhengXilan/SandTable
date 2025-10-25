/**
 * @file Platform/OpenGL/OpenglContext.cpp
 * @author LinhengXilan
 * @date 2025-10-25
 * @version build17
 * 
 * @brief OpenGL图形上下文实现
 */

#include <pch.h>

#include <Platform/OpenGL/OpenglContext.h>
#include <glad/gl.h>
#include <glfw/glfw.h>

#include <SandTable/Core.h>
#include <SandTable/Log.h>

namespace SandTable
{
	OpenglContext::OpenglContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SANDTABLE_CORE_ASSERT(windowHandle, "WindowHandle is null!");
	}

	void OpenglContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
		SANDTABLE_CORE_ASSERT(status, "Failed to initialize glad!");

		SANDTABLE_CORE_INFO("OpenGL Info:");
		SANDTABLE_CORE_INFO(" - Vendor: {0}", (char*)glGetString(GL_VENDOR));
		SANDTABLE_CORE_INFO(" - Renderer: {0}", (char*)glGetString(GL_RENDERER));
		SANDTABLE_CORE_INFO(" - Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenglContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}