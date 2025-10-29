/**
 * @file SandTable/Application.cpp
 * @author LinhengXilan
 * @date 2025-10-29
 * @version build21
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

		// Griphics Render
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<IndexBuffer> indexBuffer;
		// triangle
		// 顶点缓冲对象
		m_VertexArray.reset(VertexArray::Create());
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.9f, 0.77f, 0.93f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.77f, 0.93f, 1.0f,
			 0.0f,  0.5f, 0.0f, 1.0f, 0.97f, 0.93f, 1.0f
		};
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout = {
			{ShaderDataType::Float3, "position", false},
			{ShaderDataType::Float4, "color", false}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲对象
		unsigned int indices[] = {
			0, 1, 2
		};
		indexBuffer.reset(IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// 着色器
		std::string vertex = R"(
			#version 330 core

			layout(location = 0) in vec3 position;
			layout(location = 1) in vec4 color;
			out vec4 f_Position;

			void main()
			{
				f_Position = color;
				gl_Position = vec4(position, 1.0f);
			}
		)";
		std::string fragment = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec4 f_Position;

			void main()
			{
				color = f_Position;
			}
		)";
		m_Shader = std::make_shared<Shader>(vertex, fragment);


		// for square
		m_SquareVertexArray.reset(VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.5f, -0.5f,  0.0f,
			 0.5f, -0.5f,  0.0f,
			 0.5f,  0.5f,  0.0f,
			-0.5f,  0.5f,  0.0f
		};
		vertexBuffer.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		
		BufferLayout squareLayout = {
			{ShaderDataType::Float3, "position", false},
		};
		vertexBuffer->SetLayout(squareLayout);
		m_SquareVertexArray->AddVertexBuffer(vertexBuffer);
		
		// 索引缓冲对象
		unsigned int squareIndices[3 * 2] = {
			0, 1, 2,
			2, 3, 0
		};
		indexBuffer.reset(IndexBuffer::Create(squareIndices, 6));
		m_SquareVertexArray->SetIndexBuffer(indexBuffer);
		std::string squareVertex = R"(
			#version 330 core
		
			layout(location = 0) in vec3 position;
		
			void main()
			{
				gl_Position = vec4(position, 1.0f);
			}
		)";
		std::string squareFragment = R"(
			#version 330 core
		
			layout(location = 0) out vec4 color;
		
			void main()
			{
				color = vec4(0.8f, 0.87f, 0.74f, 1.0f);
			}
		)";
		
		m_SquareShader = std::make_shared<Shader>(squareVertex, squareFragment);
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

			m_SquareShader->Bind();
			m_SquareVertexArray->Bind();
			glDrawElements(GL_TRIANGLES, m_SquareVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Shader->Bind();
			m_VertexArray->Bind();
			glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

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