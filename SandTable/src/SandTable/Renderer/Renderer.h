/**
 * @file SandTable/Renderer/Renderer.h
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
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
		static RendererAPI::API GetRendererAPI();

		static void Init();
		static void BeginScene(const ObjectRef<Camera>& camera);
		static void EndScene();
		static void Submit(const ObjectRef<VertexArray>& vertexArray, const ObjectRef<Shader>& shader, const glm::mat4& transform = glm::mat4{1.0f});
		static void Shutdown();
	public: // 事件
		static void OnWindowResize(int32_t width, int32_t height);

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Object<SceneData> s_SceneData;
	};
}

#endif