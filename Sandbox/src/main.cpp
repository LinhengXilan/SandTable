/**
 * @file main.cpp
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief Sandbox示例程序
 */

#include <SandTable.h>
#include <SandTable/Core/EntryPoint.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Sandbox2D.h>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example")// , m_CameraController(1280.f / 720.f)
	{
		
	}

	void OnUpdate(const SandTable::TimeStep& timeStep) override
	{
		//SANDTABLE_TRACE("FPS {0} : {1}", SandTable::Application::GetClock()->GetFPS(), SandTable::Application::GetClock()->GetFrameCount());
	}

	void OnEvent(SandTable::Event& event) override
	{
		//m_CameraController.OnEvent(event);
	}

	void ImguiRender() override
	{
		// ImGui::Begin("Settings");
		// ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		// 
		// ImGui::End();
	}

private:
	// SandTable::ObjectRef<SandTable::VertexArray> m_VertexArray;
	// SandTable::ObjectRef<SandTable::VertexArray> m_SquareVertexArray;
	// SandTable::ObjectRef<SandTable::Texture2D> m_Texture;
	// SandTable::ObjectRef<SandTable::Texture2D> m_IconTexture;
	// SandTable::OrthoGraphicCameraController m_CameraController;
	// SandTable::ShaderLibrary m_ShaderLibrary;
	// glm::vec3 m_SquareColor = { 1.0f, 0.83f, 0.66f };
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		SandTable::ObjectRef<SandTable::Layer> layer = SandTable::CreateObjectRef<ExampleLayer>();
		PushLayer(layer);
		layer = SandTable::CreateObjectRef<Sandbox2D>();
		PushLayer(layer);
	}

	~Sandbox() override = default;
	
};

SandTable::Object<SandTable::Application> SandTable::CreateApplication()
{
	return CreateObject<Sandbox>();
}