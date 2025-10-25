/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @date 2025-10-25
 * @version build17
 * 
 * @brief 应用程序实现
 */

#include <pch.h>

#include <glad/gl.h>
#include <glfw/glfw.h>

#include <SandTable/Application.h>
#include <SandTable/Log.h>
#include <SandTable/Input.h>

namespace SandTable
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		SANDTABLE_CORE_ASSERT(!s_Instance, "Application already has an instance!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallbackFunc(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		m_ImguiLayer = new ImguiLayer();
		PushOverlay(m_ImguiLayer);

		// 顶点数组对象
		glGenVertexArrays(1, &m_VertexArrray);
		glBindVertexArray(m_VertexArrray);

		// 顶点缓冲对象
		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		// 索引缓冲对象
		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		unsigned char indices[] = {
			0, 1, 2
		};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glBindVertexArray(m_VertexArrray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, nullptr);

			// 层更新
			for (Layer* layer : m_LayerStack)
			{
				layer->Update();
			}

			// ImGui 渲染
			m_ImguiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->ImguiRender();
			}
			m_ImguiLayer->End();

			m_Window->Update();
		}
	}
}