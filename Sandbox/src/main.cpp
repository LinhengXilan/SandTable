#include <SandTable.h>

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}