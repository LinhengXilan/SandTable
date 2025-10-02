/**
 * @file SandTable/ImGui/ImGuiLayer.cpp
 * @author LinhengXilan
 * @date 2025-10-2
 * @version build14
 */

#include <pch.h>

#include <imgui/imgui.h>
#include <glfw/glfw.h>

#include <SandTable/ImGui/ImGuiLayer.h>
#include <Platform/OpenGL/ImGuiOpenGLRenderer.h>
#include <Platform/OpenGL/ImGuiGlfwRenderer.h>
#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Application.h>

namespace SandTable
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::Update()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& application = Application::GetInstance();
		io.DisplaySize = ImVec2(application.GetWindow().GetWidth(), application.GetWindow().GetHeight());
		
		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MousePressed>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnMousePressed));
		dispatcher.Dispatch<MouseReleased>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnMouseReleased));
		dispatcher.Dispatch<MouseMoved>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolled>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnMouseScrolled));
		dispatcher.Dispatch<KeyPressed>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleased>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTyped>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnKeyTyped));
		dispatcher.Dispatch<WindowResize>(SANDTABLE_BIND_EVENT_FUNC(ImGuiLayer::OnWindowResize));
	}

	void ImGuiLayer::Attach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		ImGui_ImplOpenGL3_Init("#version 430");
		Application& app = Application::GetInstance();
		Window* window = &app.GetWindow();
		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow()), true);
	}

	void ImGuiLayer::Detach()
	{

	}

	bool ImGuiLayer::OnMousePressed(MousePressed& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;
		return false;
	}

	bool ImGuiLayer::OnMouseReleased(MouseReleased& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMoved& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(event.GetX(), event.GetY());
		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolled& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += event.GetXOffset();
		io.MouseWheel += event.GetYOffset();
		return false;
	}

	bool ImGuiLayer::OnWindowResize(WindowResize& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, event.GetWidth(), event.GetHeight());
		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressed& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysData[event.GetKeyCode()].Down = true;
		// io.KeyCtrl = io.KeysData[GLFW_KEY_LEFT_CONTROL].Down || io.KeysData[GLFW_KEY_RIGHT_CONTROL].Down;
		// io.KeyShift = io.KeysData[GLFW_KEY_LEFT_SHIFT].Down || io.KeysData[GLFW_KEY_RIGHT_SHIFT].Down;
		// io.KeyAlt = io.KeysData[GLFW_KEY_LEFT_ALT].Down || io.KeysData[GLFW_KEY_RIGHT_ALT].Down;
		// io.KeySuper = io.KeysData[GLFW_KEY_LEFT_SUPER].Down || io.KeysData[GLFW_KEY_RIGHT_SUPER].Down;
		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleased& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysData[event.GetKeyCode()].Down = false;
		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTyped& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = event.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
		{
			io.AddInputCharacter((unsigned short)keycode);
		}
		return false;
	}

} // namespace SandTable