/**
 * @file Sandbox2D.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief Sandbox示例程序
 */

#include <Sandbox2D.h>
#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.f / 720.f)
{
	
}

void Sandbox2D::Attach()
{
	m_CameraController.SetMoveSpeed(2.0f);
	m_CameraController.SetRotationSpeed(50.0f);
	m_CameraController.AllowTranslatedSpeed(true);

	m_VertexArray = SandTable::VertexArray::Create();

	float squareVertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	SandTable::ObjectRef<SandTable::VertexBuffer> vertexBuffer = SandTable::VertexBuffer::Create(squareVertices, sizeof(squareVertices));

	SandTable::BufferLayout squareLayout = {
		{SandTable::ShaderDataType::Float3, "position", false},
	};
	vertexBuffer->SetLayout(squareLayout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	// 索引缓冲对象
	uint32_t squareIndices[] = {
		0, 1, 2,
		2, 3, 0
	};
	SandTable::ObjectRef<SandTable::IndexBuffer> indexBuffer = SandTable::IndexBuffer::Create(squareIndices, 6);
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_Shader = SandTable::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::Detach()
{

}

void Sandbox2D::ImguiRender()
{
	ImGui::Begin("Settings");

	ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnUpdate(SandTable::TimeStep timeStep)
{
	//SANDTABLE_TRACE("ExampleLayer::OnUpdate: {0} s ({1} ms)", timeStep.duration, timeStep.duration * 1000.0);
	m_CameraController.OnUpdate(timeStep);

	SandTable::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});
	SandTable::RenderCommand::Clear();

	SandTable::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_Shader)->Bind();
	std::dynamic_pointer_cast<SandTable::OpenGLShader>(m_Shader)->SetUniform("u_Color", m_SquareColor);
	
	SandTable::Renderer::Submit(m_VertexArray, m_Shader, glm::scale(glm::mat4{1.0f}, glm::vec3{1.0f}));
	SandTable::Renderer::EndScene();
}

void Sandbox2D::OnEvent(SandTable::Event& event)
{
	m_CameraController.OnEvent(event);
}