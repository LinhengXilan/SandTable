/**
 * @file SandTable/Renderer/GraphicsContext.cpp
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 图形上下文接口
 */

#include <pch.h>
#include <SandTable/Renderer/GraphicsContext.h>
#include <Platform/OpenGL/OpenGLContext.h>
#include <SandTable/Renderer/Renderer.h>

namespace SandTable
{
	Object<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
		case RendererAPI::API::OpenGL3:
			return CreateObject<OpenGLContext>(static_cast<GLFWwindow*>(window));
		default:
			return nullptr;
		}
	}
}