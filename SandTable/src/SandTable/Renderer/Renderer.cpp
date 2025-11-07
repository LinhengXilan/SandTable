/**
 * @file SandTable/Renderer/Renderer.cpp
 * @author LinhengXilan
 * @date 2025-11-7
 * @version build26
 * 
 * @brief 渲染器实现
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer.h>

namespace SandTable
{
	Renderer::SceneData* Renderer::m_SceneData = new SceneData;

	void Renderer::BeginScene(const std::shared_ptr<OrthographicCamera>& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetUniform("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		shader->SetUniform("u_ModelTransform", transform);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}