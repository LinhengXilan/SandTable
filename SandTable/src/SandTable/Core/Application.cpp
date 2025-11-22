/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 应用程序实现
 */

#include <pch.h>
#include <SandTable/Core/Application.h>
#include <SandTable/Core/Log.h>
#include <SandTable/Renderer/Renderer.h>

namespace SandTable
{
	ObjectRef<Application> Application::s_Instance;

	Application::Application()
	{
		SANDTABLE_CORE_ASSERT(!s_Instance.get(), "Application already has an instance!");
		s_Instance.reset(this);
		m_Window = Window::Create();
		m_Window->SetEventCallbackFunc(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		m_Window->SetSync(true);

		RendererAPI::SetAPI(RendererAPI::API::OpenGL); 
		Renderer::Init();

		m_ImguiLayer = CreateObjectRef<ImguiLayer>();
		PushOverlay(m_ImguiLayer);

		m_Clock = CreateObject<Clock>();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowClose>(SANDTABLE_BIND_EVENT_FUNC(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResize>(SANDTABLE_BIND_EVENT_FUNC(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.m_Handled)
			{
				break;
			}
		}
	}

	bool Application::OnWindowClose(WindowClose& event)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResize& event)
	{
		Renderer::OnWindowResize(event.GetWidth(), event.GetHeight());
		return false;
	}

	void Application::PushLayer(const ObjectRef<Layer>& layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(const ObjectRef<Layer>& overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::Run() 
	{
		while (m_Running)
		{
			m_Clock->Tick();
			SANDTABLE_CORE_TRACE("FPS {0} : {1}", m_Clock->GetFPS(), m_Clock->GetFrameCount());
			// 层更新
			for (auto& layer : m_LayerStack)
			{
				layer->OnUpdate(m_Clock->GetTimeStep());
			}

			// ImGui 渲染
			m_ImguiLayer->Begin();
			for (auto& layer : m_LayerStack)
			{
				layer->ImguiRender();
			}
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}

	ObjectRef<Window> Application::GetWindow() const
	{
		return m_Window;
	}

	ObjectRef<Application> Application::GetInstance()
	{
		return s_Instance;
	}
}