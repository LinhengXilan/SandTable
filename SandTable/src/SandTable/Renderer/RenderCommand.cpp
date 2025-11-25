/**
 * @file SandTable/Renderer/RenderCommand.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief
 */

#include <pch.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace SandTable
{
	Object<RendererAPI> RenderCommand::s_RendererAPI = CreateObject<OpenGLRendererAPI>();

	void RenderCommand::Init()
	{
		s_RendererAPI->Init();
	}

	void RenderCommand::SetClearColor(const glm::vec4& color)
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

	void RenderCommand::SetViewportSize(int32_t posX, int32_t posY, int32_t width, int32_t height)
	{
		s_RendererAPI->SetViewportSize(posX, posY, width, height);
	}
}