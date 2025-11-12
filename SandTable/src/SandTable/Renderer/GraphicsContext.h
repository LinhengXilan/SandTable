/**
 * @file SandTable/Renderer/GraphicsContext.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief 图形上下文接口
 */

#ifndef SANDTABLE_RENDERER_GRAPHICSCONTEXT_H
	#define SANDTABLE_RENDERER_GRAPHICSCONTEXT_H

namespace SandTable
{
	class GraphicsContext
	{
	public:
		GraphicsContext() = default;
		virtual ~GraphicsContext() = default;

	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}

#endif