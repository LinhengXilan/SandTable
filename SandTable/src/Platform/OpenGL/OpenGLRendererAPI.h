/**
 * @file Platform/OpenGL/OpenGLRendererAPI.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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
		void SetViewportSize(int32_t posX, int32_t posY, int32_t width, int32_t height) override;
	};
}

#endif