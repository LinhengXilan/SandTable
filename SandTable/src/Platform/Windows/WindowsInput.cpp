/**
 * @file Platform/Windows/WindowsInput.cpp
 * @author LinhengXilan
 * @date 2025-9-20
 * @version build13
 */

#include <pch.h>

#include <GLFW/glfw3.h>

#include <Platform/Windows/WindowsInput.h>
#include <SandTable/Application.h>

namespace SandTable
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMousePressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		double posX, posY;
		glfwGetCursorPos(window, &posX, &posY);
		return {(float)posX, (float)posY};
	}

	float WindowsInput::GetMousePosXImpl()
	{
		auto [posX, posY] = GetMousePosImpl();
		return posX;
	 }

	float WindowsInput::GetMousePosYImpl()
	{
		auto [posX, posY] = GetMousePosImpl();
		return posY;
	}
}