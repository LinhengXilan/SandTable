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
		//SANDTABLE_CLIENT_INFO("ExampleLayer::Update()");
		if (SandTable::Input::IsKeyPressed(KEY_TAB))
		{
			SANDTABLE_CLIENT_INFO("Tab is pressed");
		}
	}

	void OnEvent(SandTable::Event& event) override
	{
		if (event.GetEventType() == SandTable::EventType::KeyPressed)
		{
			SandTable::KeyPressed& e = (SandTable::KeyPressed&)event;
			SANDTABLE_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SandTable::ImGuiLayer());
	}

	~Sandbox() = default;
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}