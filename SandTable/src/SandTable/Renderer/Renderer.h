/**
 * @file SandTable/Renderer/Renderer.h
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief 渲染器头文件
 */

#ifndef SANDTABLE_RENDERER_RENDERER_H
	#define SANDTABLE_RENDERER_RENDERER_H

#include <SandTable/Renderer/RenderCommand.h>

namespace SandTable
{
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);


		inline static RendererAPI::API GetRendererAPI() { return RendererAPI::GetAPI(); }
	};
}

#endif