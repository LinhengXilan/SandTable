#include <SandTable.h>

class Sandbox : public SandTable::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}