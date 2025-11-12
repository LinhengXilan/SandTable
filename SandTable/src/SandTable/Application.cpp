/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief 应用程序实现
 */

#include <pch.h>
#include <SandTable/Application.h>
#include <SandTable/Log.h>

namespace SandTable
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		SANDTABLE_CORE_ASSERT(!s_Instance, "Application already has an instance!");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallbackFunc(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		m_Window->SetSync(false);

		m_ImguiLayer = std::make_unique<ImguiLayer>();
		PushOverlay(m_ImguiLayer.get());

		m_Clock = std::make_unique<Clock>();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowClose>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

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

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
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
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate(m_Clock->GetTimeStep());
			}

			// ImGui 渲染
			m_ImguiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->ImguiRender();
			}
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}
}