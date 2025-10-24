/**
 * @file Platform/OpenGL/OpenglContext.cpp
 * @author LinhengXilan
 * @date 2025-10-24
 * @version build16
 * 
 * @brief OpenGL图形上下文实现
 */

#include <pch.h>

#include <glad/gl.h>

#include <SandTable/core.h>
#include <Platform/OpenGL/OpenglContext.h>
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
	}

	void OpenglContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}