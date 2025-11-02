/**
 * @file SandTable/Renderer/Renderer.cpp
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
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

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader)
	{
		shader->Bind();
		shader->SetUniform("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}