/**
 * @file Sandbox2D.cpp
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief Sandbox示例程序
 */

#include <Sandbox2D.h>
#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <SandTable/Core/Timer/Timer.h>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.f / 720.f)
{
	
}

void Sandbox2D::Attach()
{
	m_CameraController.SetMoveSpeed(2.0f);
	m_CameraController.SetRotationSpeed(50.0f);
	m_CameraController.AllowTranslatedSpeed(true);
	m_Texture = SandTable::Texture2D::Create("assets/textures/grid.png");
	m_TimerGroup = SandTable::CreateObjectRef<SandTable::TimerGroup>();
}

void Sandbox2D::Detach()
{

}

void Sandbox2D::ImguiRender()
{
	ImGui::Begin("Settings");
	for (const auto& i : *m_TimerGroup)
	{
		ImGui::Text("%s : %3.1fms(%3.0fus)\n", i.first.c_str(), i.second, i.second * 1000.0f);
	}
	ImGui::End();
}

void Sandbox2D::OnUpdate(const SandTable::TimeStep& timeStep)
{
	m_TimerGroup->ClearDurations();

	//SANDTABLE_TRACE("ExampleLayer::OnUpdate: {0} s ({1} ms)", timeStep.duration, timeStep.duration * 1000.0);
	SandTable::Timer timer("Sandbox2D::Onupdate", m_TimerGroup);
	{
		SandTable::Timer timer1("CameraController.OnUpdate", m_TimerGroup);
		m_CameraController.OnUpdate(timeStep);
	}

	SandTable::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
	SandTable::RenderCommand::Clear();

	SandTable::Renderer2D::BeginScene(m_CameraController.GetCamera());

	{
		SandTable::Timer timer2("Draw", m_TimerGroup);
		SandTable::Renderer2D::DrawRectangle({0.0f, 0.0f}, {1.0f, 1.0f}, {0.8f, 0.2f, 0.3f, 1.0f});
		SandTable::Renderer2D::DrawRectangle({0.0f, 0.0f, -0.5f}, {12.0f, 12.0f}, m_Texture);
	}
	SandTable::Renderer2D::EndScene();
}

void Sandbox2D::OnEvent(SandTable::Event& event)
{
	m_CameraController.OnEvent(event);
}