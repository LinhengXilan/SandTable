#include <SandTable.h>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void Update() override
	{
		SANDTABLE_CLIENT_INFO("ExampleLayer::Update()");
	}

	void OnEvent(SandTable::Event& event) override
	{
		SANDTABLE_CLIENT_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() = default;
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}