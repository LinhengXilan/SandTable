/**
 * @file main.cpp
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief Sandbox示例程序
 */

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
		float width = SandTable::Application::GetInstance().GetWindow().GetWidth();
		float height = SandTable::Application::GetInstance().GetWindow().GetHeight();
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
		m_Shader = SandTable::Shader::Create(vertex, fragment);

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

		std::string squareVertex = R"(
			#version 330 core
		
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_ModelTransform;
		
			void main()
			{
				gl_Position = u_ViewProjection * u_ModelTransform * vec4(a_Position, 1.0f);
			}
		)";
		std::string squareFragment = R"(
			#version 330 core
		
			uniform vec3 u_Color;

			layout(location = 0) out vec4 color;

			void main()
			{
				color = vec4(u_Color, 1.0f);
				//color = vec4(0.8f, 0.87f, 0.74f, 1.0f);
			}
		)";
		m_SquareShader = SandTable::Shader::Create(squareVertex, squareFragment);

		std::string textureVertex = R"(
			#version 330 core
		
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TexCoord;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_ModelTransform;

			out vec2 v_TexCoord;
		
			void main()
			{
				v_TexCoord = a_TexCoord;
				gl_Position = u_ViewProjection *  u_ModelTransform * vec4(a_Position, 1.0f);

			}
		)";
		std::string textureFragment = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec2 v_TexCoord;

			uniform sampler2D u_Texture;

			void main()
			{
				color = texture(u_Texture, v_TexCoord);
			}
		)";
		m_TextureShader = SandTable::Shader::Create(textureVertex, textureFragment);
		m_Texture = SandTable::Texture2D::Create("assets/textures/grid.png");

		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_TextureShader)->SetUniform("u_Texture", 0);
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

		//glm::vec4 pink;
		//glm::vec4 orange{1.0f, 0.66f, 0.83f, 1.0f};
		//m_SquareColor = { 1.0f, 0.83f, 0.66f };

		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_SquareShader)->Bind();
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_SquareShader)->SetUniform("u_Color", m_SquareColor);


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
				SandTable::Renderer::Submit(m_SquareVertexArray, m_SquareShader, transform);
			}
		}
		m_Texture->Bind();
		SandTable::Renderer::Submit(m_SquareVertexArray, m_TextureShader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
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
	SandTable::ObjectRef<SandTable::Shader> m_Shader;
	SandTable::ObjectRef<SandTable::VertexArray> m_SquareVertexArray;
	SandTable::ObjectRef<SandTable::Shader> m_SquareShader;
	SandTable::ObjectRef<SandTable::Shader> m_TextureShader;
	SandTable::ObjectRef<SandTable::OrthographicCamera> m_Camera;
	SandTable::ObjectRef<SandTable::Texture2D> m_Texture;

	glm::vec3 m_SquarePosition;
	float m_SquareSpeed;
	glm::vec3 m_SquareColor;
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

SandTable::Object<SandTable::Application> SandTable::CreateApplication()
{
	return std::make_unique<Sandbox>();
}