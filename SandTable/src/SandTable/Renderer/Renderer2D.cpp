/**
 * @file SandTable/Renderer/Renderer2D.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 2D渲染器
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer2D.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <SandTable/Renderer/RenderCommand.h>

namespace SandTable
{
	//static Object<Renderer2DData> s_Data;
	static Renderer2DData* s_Data;

	void Renderer2D::Init()
	{
		//s_Data = CreateObject<Renderer2DData>();
		s_Data = new Renderer2DData();

		s_Data->VertexArray = VertexArray::Create();

		float squareVertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};
		ObjectRef<VertexBuffer> vertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		BufferLayout squareLayout = {
			{ShaderDataType::Float3, "position", false}
		};
		vertexBuffer->SetLayout(squareLayout);
		s_Data->VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t squareIndices[] = {
			0, 1, 2,
			2, 3, 0
		};
		ObjectRef<IndexBuffer> indexBuffer = IndexBuffer::Create(squareIndices, 6);
		s_Data->VertexArray->SetIndexBuffer(indexBuffer);

		s_Data->Shader = Shader::Create("assets/shaders/FlatColor.glsl");
	}

	void Renderer2D::Shutdown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene(const ObjectRef<OrthographicCamera>& camera)
	{
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->Shader)->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(s_Data->Shader)->SetUniform("u_ViewProjection", camera->GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{

	}

	void Renderer2D::DrawRectangle(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRectangle({position.x, position.y, 0.0f}, size, color);
	}

	void Renderer2D::DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(s_Data->Shader)->Bind();
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(s_Data->Shader)->SetUniform("u_Color", color);
		std::dynamic_pointer_cast<SandTable::OpenGLShader>(s_Data->Shader)->SetUniform("u_ModelTransform", glm::mat4{1.0f});
		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}
}