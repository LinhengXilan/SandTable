/**
 * @file SandTable/Renderer/RenderCommand.cpp
 * @author LinhengXilan
 * @version build30
 * @date 2025-11-12
 * 
 * @brief
 */

#include <pch.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace SandTable
{
	Object<RendererAPI> RenderCommand::s_RendererAPI = std::make_unique<OpenGLRendererAPI>();

	void RenderCommand::Init()
	{
		s_RendererAPI->Init();
	}

	void RenderCommand::SetClearColor(glm::vec4 color)
	{
		s_RendererAPI->SetClearColor(color);
	}
	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}
	void RenderCommand::DrawIndexed(const ObjectRef<VertexArray>& vertexArray)
	{
		s_RendererAPI->DrawIndexed(vertexArray);
	}
}