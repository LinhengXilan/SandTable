/**
 * @file SandTable/Renderer/RenderCommand.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
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

	void RenderCommand::SetViewportSize(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height)
	{
		s_RendererAPI->SetViewportSize(posX, posY, width, height);
	}
}