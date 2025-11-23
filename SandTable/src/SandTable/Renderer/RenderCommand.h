/**
 * @file SandTable/Renderer/RenderCommand.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
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
		static void SetClearColor(glm::vec4 color);
		static void Clear();
		static void DrawIndexed(const ObjectRef<VertexArray>& vertexArray);
		static void SetViewportSize(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height);
	
	private:
		static Object<RendererAPI> s_RendererAPI;
	};
}

#endif