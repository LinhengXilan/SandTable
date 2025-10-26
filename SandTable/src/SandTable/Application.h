/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build18
 * 
 * @brief 应用程序头文件
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <SandTable/core.h>
#include <SandTable/Events/Event.h>
#include <SandTable/Events/Application.h>
#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/LayerStack.h>
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Renderer/Shader.h>

namespace SandTable
{
	class SANDTABLE_DLL Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event& event);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowClose& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImguiLayer* m_ImguiLayer;
		static Application* s_Instance;

		// 图形渲染
		unsigned int m_VertexArrray;
		unsigned int m_VertexBuffer;
		unsigned int m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	};

	Application* CreateApplication();

}

#endif