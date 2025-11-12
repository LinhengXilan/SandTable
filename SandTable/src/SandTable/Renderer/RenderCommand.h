/**
 * @file SandTable/Renderer/RenderCommand.h
 * @author LinhengXilan
 * @version build30
 * @date 2025-11-12
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
		RenderCommand() = default;
		~RenderCommand() = default;

	public:
		static void Init();
		static void SetClearColor(glm::vec4 color);
		static void Clear();
		static void DrawIndexed(const ObjectRef<VertexArray>& vertexArray);
	
	private:
		static Object<RendererAPI> s_RendererAPI;
	};
}

#endif