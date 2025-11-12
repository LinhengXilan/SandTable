/**
 * @file SandTable/Renderer/Renderer.cpp
 * @author LinhengXilan
 * @version build30
 * @date 2025-11-12
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

	void Renderer::Submit(const ObjectRef<VertexArray>& vertexArray, const ObjectRef<Shader>& shader, const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->SetUniform("u_ModelTransform", transform);
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}