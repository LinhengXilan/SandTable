/**
 * @file SandTable/Renderer/RenderCommand.h
 * @author LinhengXilan
 * @version build28
 * @date 2025-11-9
 * 
 * @brief
 */

#ifndef SANDTABLE_RENDERER_RENDERCOMMAND_H
#define SANDTABLE_RENDERER_RENDERCOMMAND_H

#include <SandTable/Renderer/RendererAPI.h>

namespace SandTable
{
	class RenderCommand
	{
	public:
		inline static void SetClearColor(glm::vec4 color) { s_RendererAPI->SetClearColor(color); }
		inline static void Clear() { s_RendererAPI->Clear(); }
		inline static void DrawIndexed(const ObjectRef<VertexArray>& vertexArray) { s_RendererAPI->DrawIndexed(vertexArray); }
	private:
		static RendererAPI* s_RendererAPI;
	};
}

#endif