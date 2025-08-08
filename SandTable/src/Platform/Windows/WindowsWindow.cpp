/**
 * @file Platform/Windows/WindowsWindow.cpp
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build8
 */

#include <pch.h>

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Log.h>
#include <SandTable/Events/Application.h>
#include <SandTable/Events/Keyboard.h>
#include <SandTable/Events/Mouse.h>

namespace SandTable
{
	static bool Is_GlfwInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		SANDTABLE_CORE_ERROR("GLFW Error {0}: {1}", error, description);
	}

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

	void WindowsWindow::Init(const WindowProperty& property) {
		m_WindowData.Title = property.Title;
		m_WindowData.Width = property.Width;
		m_WindowData.Height = property.Height;
		SANDTABLE_CORE_INFO("Creating window {0} ({1}, {2})", property.Title, property.Width, property.Height);
		if (!Is_GlfwInitialized) {
			int success = glfwInit();
			SANDTABLE_CORE_ASSERT(success, "Failed to intialize glfw!");
			glfwSetErrorCallback(GLFWErrorCallback);
			Is_GlfwInitialized = true;
		}
		m_Window = glfwCreateWindow(property.Width, property.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetSync(true);

		glfwSetWindowSizeCallback(
			m_Window,
			[](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				WindowResize event(width, height);
				data.EventCallback(event);
			}
		);

		glfwSetWindowCloseCallback(
			m_Window,
			[](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowClose event;
				data.EventCallback(event);
			}
		);

		glfwSetKeyCallback(
			m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					{
						KeyPressed event(key, 0);
						data.EventCallback(event);
						break;
					}
				case GLFW_RELEASE:
					{
						KeyReleased event(key);
						data.EventCallback(event);
						break;
					}
				case GLFW_REPEAT:
					{
						KeyPressed event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			}
		);

		glfwSetMouseButtonCallback(
			m_Window,
			[](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					{
						MousePressed event(button);
						data.EventCallback(event);
						break;
					}
				case GLFW_RELEASE:
					{
						MouseReleased event(button);
						data.EventCallback(event);
						break;
					}
				}
			}
		);

		glfwSetScrollCallback(
			m_Window,
			[](GLFWwindow* window, double offsetX, double offsetY) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolled event((float)offsetX, (float)offsetY);
				data.EventCallback(event);
			}
		);

		glfwSetCursorPosCallback(
			m_Window,
			[](GLFWwindow* window, double posX, double posY) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolled event((float)posX, (float)posY);
				data.EventCallback(event);
			}
		);
		
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