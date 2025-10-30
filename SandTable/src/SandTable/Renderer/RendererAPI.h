/**
 * @file SandTable/Renderer/RendererAPI.h
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief 渲染器API头文件
 */

#ifndef SANDTABLE_RENDERER_RENDERERAPI_H
	#define SANDTABLE_RENDERER_RENDERERAPI_H

#include <glm/glm.hpp>
#include <SandTable/Renderer/VertexArray.h>

namespace SandTable
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0; 
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		static API GetAPI() { return s_API; }

	private:
		static API s_API;
	};
}

#endif