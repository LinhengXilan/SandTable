/**
 * @file main.cpp
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build18
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