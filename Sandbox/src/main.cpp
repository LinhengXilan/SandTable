/**
 * @file main.cpp
 * @author LinhengXilan
 * @date 2025-11-7
 * @version build26
 * 
 * @brief Sandbox示例程序
 */

#include <SandTable.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_SquarePosition(0.0f), m_SquareSpeed(0.1f)
	{
		// Camera
		m_Camera.reset(SandTable::OrthographicCamera::Create(-1.0f, 1.0f, -1.0f, 1.0f));
		m_Camera->SetMoveSpeed(1.0f);
		m_Camera->SetRotateSpeed(100.0f);

		// Griphics Render
		std::shared_ptr<SandTable::VertexBuffer> vertexBuffer;
		std::shared_ptr<SandTable::IndexBuffer> indexBuffer;
		// triangle
		// 顶点缓冲对象
		m_VertexArray.reset(SandTable::VertexArray::Create());
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.9f, 0.77f, 0.93f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.77f, 0.93f, 1.0f,
			 0.0f,  0.5f, 0.0f, 1.0f, 0.97f, 0.93f, 1.0f
		};
		vertexBuffer.reset(SandTable::VertexBuffer::Create(vertices, sizeof(vertices)));

		SandTable::BufferLayout layout = {
			{ SandTable::ShaderDataType::Float3, "position", false },
			{ SandTable::ShaderDataType::Float4, "color",	 false }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲对象
		unsigned int indices[] = {
			0, 1, 2};
		indexBuffer.reset(SandTable::IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// 着色器
		std::string vertex = R"(
			#version 330 core

			layout(location = 0) in vec3 a_position;
			layout(location = 1) in vec4 a_color;

			uniform mat4 u_ViewProjection;

			out vec4 v_Position;

			void main()
			{
				v_Position = a_color;
				gl_Position = u_ViewProjection * vec4(a_position, 1.0f);
			}
		)";
		std::string fragment = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec4 v_Position;

			void main()
			{
				color = v_Position;
			}
		)";
		m_Shader = std::make_shared<SandTable::Shader>(vertex, fragment);

		// for square
		m_SquareVertexArray.reset(SandTable::VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};
		vertexBuffer.reset(SandTable::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		SandTable::BufferLayout squareLayout = {
			{ SandTable::ShaderDataType::Float3, "position", false },
		};
		vertexBuffer->SetLayout(squareLayout);
		m_SquareVertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲对象
		unsigned int squareIndices[3 * 2] = {
			0, 1, 2, 2, 3, 0};
		indexBuffer.reset(SandTable::IndexBuffer::Create(squareIndices, 6));
		m_SquareVertexArray->SetIndexBuffer(indexBuffer);
		std::string squareVertex = R"(
			#version 330 core
		
			layout(location = 0) in vec3 a_position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_ModelTransform;
		
			void main()
			{
				gl_Position = u_ViewProjection *  u_ModelTransform * vec4(a_position, 1.0f);
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

		m_SquareShader = std::make_shared<SandTable::Shader>(squareVertex, squareFragment);
	}

	void OnUpdate(SandTable::TimeStep timeStep) override
	{
		SANDTABLE_TRACE("ExampleLayer::OnUpdate: {0} s ({1} ms)", timeStep.duration, timeStep.duration * 1000.0);

		if (SandTable::Input::IsKeyPressed(KEY_W))
		{
			m_Camera->Move(SandTable::OrthographicCamera::Direction::Up, timeStep);
		}
		else if (SandTable::Input::IsKeyPressed(KEY_S))
		{
			m_Camera->Move(SandTable::OrthographicCamera::Direction::Down, timeStep);
		}
		if (SandTable::Input::IsKeyPressed(KEY_A))
		{
			m_Camera->Move(SandTable::OrthographicCamera::Direction::Left, timeStep);
		}
		else if (SandTable::Input::IsKeyPressed(KEY_D))
		{
			m_Camera->Move(SandTable::OrthographicCamera::Direction::Right, timeStep);
		}

		if (SandTable::Input::IsKeyPressed(KEY_Q))
		{
			m_Camera->Rotate(SandTable::OrthographicCamera::Direction::counterclockwise, timeStep);
		}
		else if (SandTable::Input::IsKeyPressed(KEY_E))
		{
			m_Camera->Rotate(SandTable::OrthographicCamera::Direction::clockwise, timeStep);
		}

		if (SandTable::Input::IsKeyPressed(KEY_R))
		{
			m_Camera->SetPosition({0.0f, 0.0f, 0.0f});
			m_Camera->SetRotation(0.0f);
		}

		if (SandTable::Input::IsKeyPressed(KEY_UP))
		{
			m_SquarePosition.y += m_SquareSpeed * timeStep;
		}
		else if(SandTable::Input::IsKeyPressed(KEY_DOWN))
		{
			m_SquarePosition.y -= m_SquareSpeed* timeStep;
		}

		if(SandTable::Input::IsKeyPressed(KEY_LEFT))
		{
			m_SquarePosition.x -= m_SquareSpeed* timeStep;
		}
		else if (SandTable::Input::IsKeyPressed(KEY_RIGHT))
		{
			m_SquarePosition.x += m_SquareSpeed* timeStep;
		}

		glm::mat4 scale = glm::scale(glm::mat4{1.0f}, glm::vec3{0.1f});

		SandTable::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
		SandTable::RenderCommand::Clear();
		SandTable::Renderer::BeginScene(m_Camera);

		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				glm::vec3 pos{i * 0.11f, j * 0.11f, 0.0f};
				glm::mat4 transform = glm::translate(glm::mat4{1.0f}, pos) * scale;
				SandTable::Renderer::Submit(m_SquareVertexArray, m_SquareShader, transform);
			}
		}
		// SandTable::Renderer::Submit(m_VertexArray, m_Shader);
		SandTable::Renderer::EndScene();
	}

	void OnEvent(SandTable::Event& event) override
	{
		
	}

	void ImguiRender() override
	{

	}

private:
	std::shared_ptr<SandTable::VertexArray> m_VertexArray;
	std::shared_ptr<SandTable::Shader> m_Shader;
	std::shared_ptr<SandTable::VertexArray> m_SquareVertexArray;
	std::shared_ptr<SandTable::Shader> m_SquareShader;
	std::shared_ptr<SandTable::OrthographicCamera> m_Camera;

	glm::vec3 m_SquarePosition;
	float m_SquareSpeed;
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() override = default;
};

SandTable::Application* SandTable::CreateApplication()
{
	return new Sandbox();
}