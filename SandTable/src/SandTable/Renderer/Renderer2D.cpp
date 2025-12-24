/**
 * @file SandTable/Renderer/Renderer2D.cpp
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
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
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		ObjectRef<VertexBuffer> vertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));

		BufferLayout layout = {
			{ShaderDataType::Float3, "a_Position", false},
			{ShaderDataType::Float2, "a_CooedTex", false}
		};
		vertexBuffer->SetLayout(layout);
		s_Data->VertexArray->AddVertexBuffer(vertexBuffer);
		uint32_t squareIndices[] = {
			0, 1, 2,
			2, 3, 0
		};
		ObjectRef<IndexBuffer> indexBuffer = IndexBuffer::Create(squareIndices, 6);
		s_Data->VertexArray->SetIndexBuffer(indexBuffer);
		s_Data->Shader2D = Shader::Create("assets/shaders/Renderer2D/Rectangle.glsl");
	}

	void Renderer2D::Shutdown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene(const ObjectRef<OrthographicCamera>& camera)
	{
		s_Data->Shader2D->Bind();
		s_Data->Shader2D->SetData("u_ViewProjection", camera->GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{

	}

	void Renderer2D::DrawRectangle(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRectangle(glm::vec3(position.x, position.y, 0.0f), size, color, Texture2D::Create());
	}

	void Renderer2D::DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRectangle(position, size, color, Texture2D::Create());		
	}

	void Renderer2D::DrawRectangle(const glm::vec2& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRectangle(glm::vec3(position.x, position.y, 0.0f), size, tintColor, texture, tilingFactor);
	}

	void Renderer2D::DrawRectangle(const glm::vec3& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRectangle(position, size, tintColor, texture, tilingFactor);
	}

	void Renderer2D::DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, const ObjectRef<Texture2D>& texture, float tilingFactor)
	{
		s_Data->Shader2D->SetData("u_Color", color);
		s_Data->Shader2D->SetData("u_TilingFactor", tilingFactor);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), {size.x, size.y, 0.0f});
		s_Data->Shader2D->SetData("u_ModelTransform", transform);
		texture->Bind(0);
		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}

	void Renderer2D::DrawRotatedRectangle(const glm::vec2& position, float rotation, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRotatedRectangle(glm::vec3(position.x, position.y, 0.0f), rotation, size, color, Texture2D::Create());
	}

	void Renderer2D::DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& color)
	{
		DrawRotatedRectangle(position, rotation, size, color, Texture2D::Create());
	}

	void Renderer2D::DrawRotatedRectangle(const glm::vec2& position, float rotation, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRotatedRectangle(glm::vec3(position.x, position.y, 0.0f), rotation, size, tintColor, texture, tilingFactor);
	}

	void Renderer2D::DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor, const glm::vec4& tintColor)
	{
		DrawRotatedRectangle(position, rotation, size, tintColor, texture, tilingFactor);
	}

	void Renderer2D::DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& color, const ObjectRef<Texture2D>& texture, float tilingFactor)
	{
		s_Data->Shader2D->SetData("u_Color", color);
		s_Data->Shader2D->SetData("u_TilingFactor", tilingFactor);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
							* glm::rotate(glm::mat4(1.0f), rotation, {0.0f, 0.0f, 1.0f})
							* glm::scale(glm::mat4(1.0f), {size.x, size.y, 0.0f});
		s_Data->Shader2D->SetData("u_ModelTransform", transform);
		texture->Bind(0);
		s_Data->VertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->VertexArray);
	}
}