/**
 * @file SandTable/Renderer/RendererAPI.h
 * @author LinhengXilan
 * @version build30
 * @date 2025-11-12
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
		RendererAPI() = default;
		virtual ~RendererAPI() = default;

	public:
		static API GetAPI();

		virtual void Init() = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0; 
		virtual void DrawIndexed(const ObjectRef<VertexArray>& vertexArray) = 0;

	private:
		static API s_API;
		static bool s_IsAPIInitialized;
	};
}

#endif