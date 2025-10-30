/**
 * @file Platform/OpenGL/OpenGLRendererAPI.h
 * @author LinhengXilan
 * @date 2025-10-30
 * @version build22
 * 
 * @brief OpenGL渲染器API头文件
 */

#ifndef PLATFORM_OPENGL_OPENGLRENDERERAPI_H
	#define PLATFORM_OPENGL_OPENGLRENDERERAPI_H

#include <SandTable/Renderer/RendererAPI.h>

namespace SandTable
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;
		void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};
}

#endif