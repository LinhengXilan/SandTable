/**
 * @file Platform/OpenGL/OpenGLContext.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief OpenGL图形上下文实现
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLContext.h>
#include <glad/gl.h>
#include <glfw/glfw.h>
#include <SandTable/Core/Core.h>
#include <SandTable/Core/Log.h>

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

#ifdef SANDTABLE_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		SANDTABLE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "SandTable requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}