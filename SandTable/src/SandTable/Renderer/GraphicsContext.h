/**
 * @file SandTable/Renderer/GraphicsContext.h
 * @author LinhengXilan
 * @date 2025-10-24
 * @version build16
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
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	private:

	};
}

#endif