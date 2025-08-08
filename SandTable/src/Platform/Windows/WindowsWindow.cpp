/**
 * @file Log.h
 * @author LinhengXilan
 * @date 2025-8-8
 * @version build7
 */

#include <pch.h>

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Log.h>

namespace SandTable
{
	static bool Is_GlfwInitialized = false;

	Window* Window::Create(const WindowProperty& property)
	{
		return new WindowsWindow(property);
	}

	WindowsWindow::WindowsWindow(const WindowProperty& property)
	{
		Init(property);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperty& property)
	{
		m_WindowData.Title = property.Title;
		m_WindowData.Width = property.Width;
		m_WindowData.Height = property.Height;
		SANDTABLE_CORE_INFO("Creating window {0} ({1}, {2})", property.Title, property.Width, property.Height);
		if (!Is_GlfwInitialized)
		{
			int success = glfwInit();
			SANDTABLE_CORE_ASSERT(success, "Failed to intialize glfw!");
			Is_GlfwInitialized = true;
		}
		m_Window = glfwCreateWindow(property.Width, property.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_WindowData.Sync = enabled;
	}

	bool WindowsWindow::IsSync() const
	{
		return m_WindowData.Sync;
	}

}