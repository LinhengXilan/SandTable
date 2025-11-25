/**
 * @file SandTable/Renderer/Renderer2D.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 2D渲染器
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer2D.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <glm/gtc/matrix_transform.hpp>

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
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		ObjectRef<VertexBuffer> vertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));

		BufferLayout squareLayout = {
			{ShaderDataType::Float3, "a_Position", false},
			{ShaderDataType::Float2, "a_CooedTex", false}
		};
		vertexBuffer->SetLayout(squareLayout);
		s_Data->VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t squareIndices[] = {
			0, 1, 2,
			2, 3, 0
		};
		ObjectRef<IndexBuffer> indexBuffer = IndexBuffer::Create(squareIndices, 6);
		s_Data->VertexArray->SetIndexBuffer(indexBuffer);

		s_Data->ColorShader = Shader::Create("assets/shaders/Renderer2D/Rectangle.glsl");
		s_Data->TextureShader = Shader::Create("assets/shaders/Renderer2D/Rectangle_Texture.glsl");
	}

	void Renderer2D::Shutdown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene(const ObjectRef<OrthographicCamera>& camera)
	{
		s_Data->ColorShader->Bind();
		s_Data->ColorShader->SetData("u_ViewProjection", camera->GetViewProjectionMatrix());
		s_Data->TextureShader->Bind();
		s_Data->TextureShader->SetData("u_ViewProjection", camera->GetViewProjectionMatrix());
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
		s_Data->ColorShader->Bind();
		s_Data->ColorShader->SetData("u_Color", color);
		glm::mat4 transform = glm::translate(glm::mat4{1.0f}, position) * glm::scale(glm::mat4{1.0f}, {size.x, size.y, 0.0f});
		s_Data->ColorShader->SetData("u_ModelTransform", transform);
		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}

	void Renderer2D::DrawRectangle(const glm::vec2& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture)
	{
		DrawRectangle({position.x, position.y, 0.0f}, size, texture);
	}

	void Renderer2D::DrawRectangle(const glm::vec3& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture)
	{
		s_Data->TextureShader->Bind();
		//s_Data->Shader->SetData("u_Texture", texture);
		glm::mat4 transform = glm::translate(glm::mat4{1.0f}, position) * glm::scale(glm::mat4{1.0f}, {size.x, size.y, 0.0f});
		s_Data->TextureShader->SetData("u_ModelTransform", transform);
		texture->Bind(0);
		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}
}