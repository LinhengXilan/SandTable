/**
 * @file SandTable/Renderer/RenderCommand.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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
		RenderCommand() = delete;
		~RenderCommand() = delete;

	public:
		static void Init();
		static void SetClearColor(const glm::vec4& color);
		static void Clear();
		static void DrawIndexed(const ObjectRef<VertexArray>& vertexArray);
		static void SetViewportSize(int32_t posX, int32_t posY, int32_t width, int32_t height);
	
	private:
		static Object<RendererAPI> s_RendererAPI;
	};
}

#endif