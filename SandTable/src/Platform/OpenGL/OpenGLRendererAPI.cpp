/**
 * @file Platform/OpenGL/OpenGLRendererAPI.cpp
 * @author LinhengXilan
 * @version build30
 * @date 2025-11-12
 * 
 * @brief OpenGL渲染器API实现
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>
#include <glad/gl.h>

namespace SandTable
{
	void OpenGLRendererAPI::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const ObjectRef<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}