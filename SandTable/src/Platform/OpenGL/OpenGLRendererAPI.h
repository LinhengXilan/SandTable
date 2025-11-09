/**
 * @file Platform/OpenGL/OpenGLRendererAPI.h
 * @author LinhengXilan
 * @version build28
 * @date 2025-11-9
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
		void DrawIndexed(const ObjectRef<VertexArray>& vertexArray) override;
	};
}

#endif