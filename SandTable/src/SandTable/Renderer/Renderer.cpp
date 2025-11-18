/**
 * @file SandTable/Renderer/Renderer.cpp
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief 渲染器实现
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLShader.h>

namespace SandTable
{
	Renderer::SceneData* Renderer::m_SceneData = new SceneData;

	void Renderer::Init()
	{
		RenderCommand::Init();
	}

	void Renderer::BeginScene(const ObjectRef<OrthographicCamera>& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	const RendererAPI::API Renderer::GetRendererAPI()
	{
		return RendererAPI::GetAPI();
	}

	void Renderer::Submit(const ObjectRef<VertexArray>& vertexArray, const ObjectRef<Shader>& shader, const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ModelTransform", transform);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

	/* vvv 事件 vvv */
	void Renderer::OnWindowResize(uint16_t width, uint16_t height)
	{
		RenderCommand::SetViewportSize(0, 0, width, height);
	}
}