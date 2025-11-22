/**
 * @file Platform/Windows/WindowsInput.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 */

#include <pch.h>

#include <glfw/glfw.h>

#include <Platform/Windows/WindowsInput.h>
#include <SandTable/Core/Application.h>

namespace SandTable
{
	Object<Input> Input::s_Instance = CreateObject<WindowsInput>();

	const bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance()->GetWindow()->GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	const bool WindowsInput::IsMousePressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance()->GetWindow()->GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	const std::pair<float, float> WindowsInput::GetMousePosImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::GetInstance()->GetWindow()->GetNativeWindow());
		double posX, posY;
		glfwGetCursorPos(window, &posX, &posY);
		return {(float)posX, (float)posY};
	}

	const float WindowsInput::GetMousePosXImpl()
	{
		auto [posX, posY] = GetMousePosImpl();
		return posX;
	 }

	const float WindowsInput::GetMousePosYImpl()
	{
		auto [posX, posY] = GetMousePosImpl();
		return posY;
	}
}