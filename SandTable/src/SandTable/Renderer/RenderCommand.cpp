/**
 * @file SandTable/Renderer/RenderCommand.cpp
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief
 */

#include <pch.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace SandTable
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}