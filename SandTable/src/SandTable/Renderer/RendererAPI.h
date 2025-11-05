/**
 * @file SandTable/Renderer/RendererAPI.h
 * @author LinhengXilan
 * @date 2025-11-5
 * @version build24
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
		enum class API : unsigned char
		{
			None = 0,
			OpenGL = 0x10, OpenGL3 = 0x11,
			DirectX = 0x20
		};

	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0; 
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		static API GetAPI();

	private:
		static API s_API;
		static bool s_IsAPIInitialized;
	};
}

#endif