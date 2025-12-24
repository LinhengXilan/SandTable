/**
 * @file SandTable/Core/Application.cpp
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 * 
 * @brief 应用程序实现
 */

#include <pch.h>
#include <SandTable/Core/Application.h>
#include <SandTable/Core/Log.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Debug/Instrumentor.h>
#include <SandTable/ImGui/ImguiLayer.h>

namespace SandTable
{
	ObjectRef<Application> Application::s_Instance;
	ObjectRef<Clock> Application::s_Clock;

	Application::Application()
	{
		SANDTABLE_CORE_ASSERT(!s_Instance.get(), "Application already has an instance!");
		s_Instance.reset(this);

		RendererAPI::SetAPI(RendererAPI::API::OpenGL);
		m_Window = Window::Create();
		m_Window->SetEventCallbackFunc(SANDTABLE_BIND_EVENT_FUNC(Application::OnEvent));
		m_Window->SetSync(false);
		Renderer::Init();

		m_ImguiLayer = new ImguiLayer();
		PushOverlay(m_ImguiLayer);

		s_Clock = CreateObjectRef<Clock>();
	}

	Application::~Application()
	{
		Renderer::Shutdown();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowClose>(SANDTABLE_BIND_EVENT_FUNC(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResize>(SANDTABLE_BIND_EVENT_FUNC(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(event);
			if (event.m_Handled)
			{
				break;
			}
		}
	}

	bool Application::OnWindowClose(WindowClose& event)
	{
		o_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResize& event)
	{
		int32_t width = event.GetWidth();
		int32_t height = event.GetHeight();
		if (width == 0 || height == 0)
		{
			o_Minimized = true;
		}
		Renderer::OnWindowResize(width, height);
		return false;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->Attach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->Attach();
	}

	void Application::Run()
	{
		SANDTABLE_PROFILE_FUNCTION();
		while (o_Running)
		{
			s_Clock->Tick();
			if (!o_Minimized)
			{
				// 层更新
				{
					SANDTABLE_PROFILE_SCOPE("LayerStack OnUpdate");
					for (auto layer : m_LayerStack)
					{
						layer->OnUpdate(s_Clock->GetTimeStep());
					}
				}
				// ImGui 渲染
				{
					SANDTABLE_PROFILE_SCOPE("LayerStack ImguiRender");
					m_ImguiLayer->Begin();
					for (auto layer : m_LayerStack)
					{
						layer->ImguiRender();
					}
					m_ImguiLayer->End();
				}
			}

			m_Window->OnUpdate();
		}
	}

	const ObjectRef<Window>& Application::GetWindow() const
	{
		return m_Window;
	}

	const ObjectRef<Clock>& Application::GetClock()
	{
		return s_Clock;
	}

	const ObjectRef<Application>& Application::GetInstance()
	{
		return s_Instance;
	}
}