/**
 * @file SandTable/Application.h
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief 应用程序头文件
 */

#ifndef SANDTABLE_APPLICATION_H
#define SANDTABLE_APPLICATION_H

#include <Platform/Windows/WindowsWindow.h>
#include <SandTable/LayerStack.h>
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/VertexArray.h>
#include <SandTable/Renderer/Camera.h>

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

		// 图形渲染
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_Shader;

		std::shared_ptr<VertexArray> m_SquareVertexArray;
		std::shared_ptr<Shader> m_SquareShader;

		std::shared_ptr<OrthographicCamera> m_Camera;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

#endif