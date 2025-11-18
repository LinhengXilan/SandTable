/**
 * @file Platform/OpenGL/OpenGLRendererAPI.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
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
		OpenGLRendererAPI() = default;
		~OpenGLRendererAPI() override = default;

	public:
		void Init() override;
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;
		void DrawIndexed(const ObjectRef<VertexArray>& vertexArray) override;
		void SetViewportSize(uint16_t posX, uint16_t posY, uint16_t width, uint16_t height) override;
	};
}

#endif