/**
 * @file SandTable/ImGui/ImguiLayer.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief Imgui层实现
 */

#include <pch.h>

#include <imgui/imgui.h>
#include <glfw/glfw.h>

#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Imgui/ImguiOpengl.h>
#include <SandTable/Imgui/ImguiGlfw.h>
#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Core/Application.h>

namespace SandTable
{
	ImguiLayer::ImguiLayer()
		: Layer("ImguiLayer")
	{

	}

	void ImguiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImguiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		auto app = Application::GetInstance();
		auto window = app->GetWindow();
		io.DisplaySize = ImVec2((float)window->GetWidth(), (float)window->GetHeight());
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImguiLayer::Detach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImguiLayer::ImguiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImguiLayer::Attach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
		auto app = Application::GetInstance();
		GLFWwindow* window = static_cast<GLFWwindow*>(app->GetWindow()->GetNativeWindow());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 430");
	}

	/*void ImguiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MousePressed>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnMousePressed));
		dispatcher.Dispatch<MouseReleased>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnMouseReleased));
		dispatcher.Dispatch<MouseMoved>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolled>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnMouseScrolled));
		dispatcher.Dispatch<KeyPressed>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleased>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTyped>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnKeyTyped));
		dispatcher.Dispatch<WindowResize>(SANDTABLE_BIND_EVENT_FUNC(ImguiLayer::OnWindowResize));
	}

	bool ImguiLayer::OnMousePressed(MousePressed& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;
		return false;
	}

	bool ImguiLayer::OnMouseReleased(MouseReleased& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;
		return false;
	}

	bool ImguiLayer::OnMouseMoved(MouseMoved& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(event.GetX(), event.GetY());
		return false;
	}

	bool ImguiLayer::OnMouseScrolled(MouseScrolled& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += event.GetXOffset();
		io.MouseWheel += event.GetYOffset();
		return false;
	}

	bool ImguiLayer::OnWindowResize(WindowResize& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)event.GetWidth(), (float)event.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, event.GetWidth(), event.GetHeight());
		return false;
	}

	bool ImguiLayer::OnKeyPressed(KeyPressed& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysData[event.GetKeyCode()].Down = true;
		return false;
	}

	bool ImguiLayer::OnKeyReleased(KeyReleased& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysData[event.GetKeyCode()].Down = false;
		return false;
	}

	bool ImguiLayer::OnKeyTyped(KeyTyped& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = event.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
		{
			io.AddInputCharacter((unsigned short)keycode);
		}
		return false;
	}*/

}