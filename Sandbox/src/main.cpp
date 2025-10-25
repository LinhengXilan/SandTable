/**
 * @file main.cpp
 * @author LinhengXilan
 * @date 2025-10-25
 * @version build17
 * 
 * @brief SandTable示例程序
 */

#include <SandTable.h>
#include <imgui/imgui.h>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void Update() override
	{

	}

	void OnEvent(SandTable::Event& event) override
	{
	
	}

	void ImguiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() override = default;
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}