/**
 * @file SandTable/Renderer/Renderer.h
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief 着色器类
 */

#ifndef SANDTABLE_RENDERER_RENDERER_H
	#define SANDTABLE_RENDERER_RENDERER_H

namespace SandTable
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};

	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		inline static RendererAPI GetRendererAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};
}

#endif