#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef SANDTABLE_PLATFORM_WINDOWS

extern SandTable::Application* SandTable::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "SandTable Engine\n";
	auto app = SandTable::CreateApplication();
	app->Run();
	delete app;
}

#endif

#endif