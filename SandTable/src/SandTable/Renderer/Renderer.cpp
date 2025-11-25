/**
 * @file SandTable/Renderer/Renderer.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 渲染器实现
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <SandTable/Renderer/Renderer2D.h>

namespace SandTable
{
	Object<Renderer::SceneData> Renderer::s_SceneData = CreateObject<SceneData>();

	void Renderer::Init()
	{
		RenderCommand::Init();
		Renderer2D::Init();
	}

	void Renderer::BeginScene(const ObjectRef<Camera>& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	RendererAPI::API Renderer::GetRendererAPI()
	{
		return RendererAPI::GetAPI();
	}

	void Renderer::Submit(const ObjectRef<VertexArray>& vertexArray, const ObjectRef<Shader>& shader, const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ModelTransform", transform);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

	/* vvv 事件 vvv */
	void Renderer::OnWindowResize(int32_t width, int32_t height)
	{
		RenderCommand::SetViewportSize(0, 0, width, height);
	}
}