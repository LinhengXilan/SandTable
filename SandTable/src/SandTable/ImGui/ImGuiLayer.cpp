/**
 * @file SandTable/ImGui/ImguiLayer.cpp
 * @author LinhengXilan
 * @date 2025-10-23
 * @version build15
 * 
 * @brief Imgui≤„ µœ÷
 */

#include <pch.h>

#include <imgui/imgui.h>
#include <glfw/glfw.h>

#include <SandTable/ImGui/ImguiLayer.h>
#include <Platform/OpenGL/ImguiOpengl.h>
#include <Platform/OpenGL/ImguiGlfw.h>
#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/Application.h>

namespace SandTable
{
	ImguiLayer::ImguiLayer()
		: Layer("ImguiLayer")
	{

	}

	ImguiLayer::~ImguiLayer()
	{

	}

	void ImguiLayer::Update()
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

	void ImguiLayer::OnEvent(Event& event)
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

	void ImguiLayer::Attach()
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

	void ImguiLayer::Detach()
	{

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
		io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
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
	}

} // namespace SandTable