/**
 * @file main.cpp
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 * 
 * @brief Sandbox示例程序
 */

#define SANDTABLE_DEBUG

#include <SandTable.h>
#include <SandTable/Core/EntryPoint.h>
#include <Sandbox2D.h>

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox() override = default;
	
};

SandTable::Object<SandTable::Application> SandTable::CreateApplication()
{
	return CreateObject<Sandbox>();
}