/**
 * @file SandTable/Renderer/Renderer.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 渲染器头文件
 */

#ifndef SANDTABLE_RENDERER_RENDERER_H
	#define SANDTABLE_RENDERER_RENDERER_H

#include <SandTable/Renderer/RenderCommand.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/Camera.h>

namespace SandTable
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

	public:
		static const RendererAPI::API GetRendererAPI();

		static void Init();
		static void BeginScene(const ObjectRef<Camera>& camera);
		static void EndScene();
		static void Submit(const ObjectRef<VertexArray>& vertexArray, const ObjectRef<Shader>& shader, const glm::mat4& transform = glm::mat4{1.0f});

	public: // 事件
		static void OnWindowResize(uint16_t width, uint16_t height);

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Object<SceneData> s_SceneData;
	};
}

#endif