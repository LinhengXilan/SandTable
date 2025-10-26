/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief 应用程序实现
 */

#include <pch.h>
#include <glad/gl.h>
#include <glfw/glfw.h>
#include <SandTable/Application.h>
#include <SandTable/Log.h>
#include <SandTable/Input.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

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
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		// 顶点缓冲对象
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		// 索引缓冲对象
		unsigned int indices[] = {
			0, 1, 2
		};
		m_IndexBuffer.reset(IndexBuffer::Create(indices, 3));
		std::string vertex = R"(
			#version 330 core

			layout(location = 0) in vec3 position;
			out vec3 f_Position;

			void main()
			{
				f_Position = position;
				gl_Position = vec4(position, 1.0f);
			}
		)";
		std::string fragment = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 f_Position;

			void main()
			{
				color = vec4(1.0f, 0.87f, 0.93f, 1.0f) * 0.8f + vec4(f_Position, 1.0f) * 0.2f ;
			}
		)";

		// 着色器
		m_Shader = std::make_unique<Shader>(vertex, fragment);

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

			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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