/**
 * @file main.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief Sandbox示例程序
 */

#include <SandTable.h>
#include <SandTable/Core/EntryPoint.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Sandbox2D.h>

class ExampleLayer : public SandTable::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.f / 720.f)
	{
		// Camera
		m_CameraController.SetMoveSpeed(1.0f);
		m_CameraController.SetRotationSpeed(100.0f);

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

		textureShader->Bind();
		textureShader->SetData("u_Texture", 0);
	}

	void OnUpdate(const SandTable::TimeStep& timeStep) override
	{
		//SANDTABLE_TRACE("ExampleLayer::OnUpdate: {0} s ({1} ms)", timeStep.duration, timeStep.duration * 1000.0);
		m_CameraController.OnUpdate(timeStep);
		glm::mat4 scale = glm::scale(glm::mat4{1.0f}, glm::vec3{0.1f});

		SandTable::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
		SandTable::RenderCommand::Clear();
		SandTable::Renderer::BeginScene(m_CameraController.GetCamera());

		m_ShaderLibrary.GetShader("Square")->Bind();
		m_ShaderLibrary.GetShader("Square")->SetData("u_Color", m_SquareColor);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				glm::vec3 pos{i * 0.11f, j * 0.11f, 0.0f};
				glm::mat4 transform = glm::translate(glm::mat4{1.0f}, pos) * scale;
				SandTable::Renderer::Submit(m_SquareVertexArray, m_ShaderLibrary.GetShader("Square"), transform);
			}
		}
		m_Texture->Bind();
		auto textureShader = m_ShaderLibrary.GetShader("Texture");
		SandTable::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
		m_IconTexture->Bind();
		SandTable::Renderer::Submit(m_SquareVertexArray, textureShader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
		SandTable::Renderer::EndScene();
	}

	void OnEvent(SandTable::Event& event) override
	{
		m_CameraController.OnEvent(event);
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
	SandTable::ObjectRef<SandTable::Texture2D> m_Texture;
	SandTable::ObjectRef<SandTable::Texture2D> m_IconTexture;
	SandTable::OrthoGraphicCameraController m_CameraController;
	SandTable::ShaderLibrary m_ShaderLibrary;
	glm::vec3 m_SquareColor = { 1.0f, 0.83f, 0.66f };
};

class Sandbox : public SandTable::Application
{
public:
	Sandbox()
	{
		//SandTable::ObjectRef<SandTable::Layer> layer = SandTable::CreateObjectRef<ExampleLayer>();
		//PushLayer(layer);
		SandTable::ObjectRef<SandTable::Layer> layer = SandTable::CreateObjectRef<Sandbox2D>();
		PushLayer(layer);
	}

	~Sandbox() override = default;
	
};

SandTable::Object<SandTable::Application> SandTable::CreateApplication()
{
	return CreateObject<Sandbox>();
}