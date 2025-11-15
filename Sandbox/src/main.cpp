/**
 * @file main.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief Sandbox示例程序
 */

#define SANDTABLE_PLATFORM_WINDOWS 

#include <SandTable.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_SquarePosition(0.0f), m_SquareSpeed(0.1f), m_SquareColor(1.0f, 0.83f, 0.66f)
	{
		// Camera
		float width = SandTable::Application::GetInstance()->GetWindow()->GetWidth();
		float height = SandTable::Application::GetInstance()->GetWindow()->GetHeight();
		m_Camera = SandTable::OrthographicCamera::Create(-1.0f * width / height, 1.0f * width / height, -1.0f, 1.0f);
		m_Camera->SetMoveSpeed(1.0f);
		m_Camera->SetRotateSpeed(100.0f);

		// Griphics Render
		SandTable::ObjectRef<SandTable::VertexBuffer> vertexBuffer;
		SandTable::ObjectRef<SandTable::IndexBuffer> indexBuffer;
		// triangle
		// 顶点缓冲对象
		m_VertexArray = SandTable::VertexArray::Create();
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.9f, 0.77f, 0.93f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.77f, 0.93f, 1.0f,
			 0.0f,  0.5f, 0.0f, 1.0f, 0.97f, 0.93f, 1.0f
		};
		vertexBuffer = SandTable::VertexBuffer::Create(vertices, sizeof(vertices));

		SandTable::BufferLayout layout = {
			{ SandTable::ShaderDataType::Float3, "position", false },
			{ SandTable::ShaderDataType::Float4, "color",	 false }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲对象
		unsigned int indices[] = {
			0, 1, 2};
		indexBuffer = SandTable::IndexBuffer::Create(indices, 3);
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// for square
		m_SquareVertexArray = SandTable::VertexArray::Create();
		float squareVertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		vertexBuffer = SandTable::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		SandTable::BufferLayout squareLayout = {
			{SandTable::ShaderDataType::Float3, "position", false},
			{SandTable::ShaderDataType::Float2, "texCoord", false}
		};
		vertexBuffer->SetLayout(squareLayout);
		m_SquareVertexArray->AddVertexBuffer(vertexBuffer);

		// 索引缓冲对象
		unsigned int squareIndices[3 * 2] = {
			0, 1, 2, 2, 3, 0
		};
		indexBuffer = SandTable::IndexBuffer::Create(squareIndices, 6);
		m_SquareVertexArray->SetIndexBuffer(indexBuffer);

		auto squareShader = m_ShaderLibrary.Load("assets/shaders/Square.glsl");
		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");
		m_Texture = SandTable::Texture2D::Create("assets/textures/grid.png");
		m_IconTexture = SandTable::Texture2D::Create("assets/icons/icon.png");

		std::dynamic_pointer_cast<SandTable::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(textureShader)->SetUniform("u_Texture", 0);
	}

	void OnUpdate(SandTable::TimeStep timeStep) override
	{
		//SANDTABLE_TRACE("ExampleLayer::OnUpdate: {0} s ({1} ms)", timeStep.duration, timeStep.duration * 1000.0);

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
			m_SquarePosition.y += m_SquareSpeed * timeStep.duration;
		}
		else if(SandTable::Input::IsKeyPressed(KEY_DOWN))
		{
			m_SquarePosition.y -= m_SquareSpeed * timeStep.duration;
		}

		if(SandTable::Input::IsKeyPressed(KEY_LEFT))
		{
			m_SquarePosition.x -= m_SquareSpeed * timeStep.duration;
		}
		else if (SandTable::Input::IsKeyPressed(KEY_RIGHT))
		{
			m_SquarePosition.x += m_SquareSpeed * timeStep.duration;
		}

		glm::mat4 scale = glm::scale(glm::mat4{1.0f}, glm::vec3{0.1f});

		SandTable::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
		SandTable::RenderCommand::Clear();
		SandTable::Renderer::BeginScene(m_Camera);

		//glm::vec4 pink;
		//glm::vec4 orange{1.0f, 0.66f, 0.83f, 1.0f};
		//m_SquareColor = { 1.0f, 0.83f, 0.66f };

		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_ShaderLibrary.GetShader("Square"))->Bind();
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_ShaderLibrary.GetShader("Square"))->SetUniform("u_Color", m_SquareColor);


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				glm::vec3 pos{i * 0.11f, j * 0.11f, 0.0f};
				glm::mat4 transform = glm::translate(glm::mat4{1.0f}, pos) * scale;
				//if ((i + j) % 2 == 0)
				//{
				//	std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_SquareShader)->SetUniform("u_Color", pink);
				//}
				//else
				//{
				//	std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_SquareShader)->SetUniform("u_Color", orange);
				//}
				SandTable::Renderer::Submit(m_SquareVertexArray, m_ShaderLibrary.GetShader("Square"), transform);
			}
		}
		m_Texture->Bind();
		auto textureShader = m_ShaderLibrary.GetShader("Texture");
		SandTable::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
		m_IconTexture->Bind();
		SandTable::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
		// SandTable::Renderer::Submit(m_VertexArray, m_Shader);
		SandTable::Renderer::EndScene();
	}

	void OnEvent(SandTable::Event& event) override
	{
		
	}

	void ImguiRender() override
	{
		ImGui::Begin("Settings");

		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();
	}

private:
	SandTable::ObjectRef<SandTable::VertexArray> m_VertexArray;
	SandTable::ObjectRef<SandTable::VertexArray> m_SquareVertexArray;
	SandTable::ObjectRef<SandTable::OrthographicCamera> m_Camera;
	SandTable::ObjectRef<SandTable::Texture2D> m_Texture;
	SandTable::ObjectRef<SandTable::Texture2D> m_IconTexture;
	SandTable::ShaderLibrary m_ShaderLibrary;

	glm::vec3 m_SquarePosition;
	float m_SquareSpeed;
	glm::vec3 m_SquareColor;
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		layer = std::make_shared<ExampleLayer>();
		PushLayer(layer);
	}
	~Sandbox() override = default;

private:
	SandTable::ObjectRef<SandTable::Layer> layer;
};

SandTable::Object<SandTable::Application> SandTable::CreateApplication()
{
	return std::make_unique<Sandbox>();
}