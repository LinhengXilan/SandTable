/**
 * @file SandTable/Renderer/Renderer2D.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 2D渲染器
 */

#ifndef SANDTABLE_RENDERER_RENDERER2D_H
#define SANDTABLE_RENDERER_RENDERER2D_H

#include <SandTable/Renderer/Camera.h>
#include <glm/glm.hpp>
#include <SandTable/Renderer/VertexArray.h>
#include <SandTable/Renderer/Shader.h>

namespace SandTable
{
	struct Renderer2DData
	{
		ObjectRef<VertexArray> VertexArray;
		ObjectRef<Shader> Shader;
	};

	class Renderer2D
	{
	public:
		Renderer2D() = delete;
		~Renderer2D() = delete;

	public:
		static void Init();
		static void Shutdown();

		/**
		 * @brief 开始一个2D场景
		 * @param camera 正交相机
		 */
		static void BeginScene(const ObjectRef<OrthographicCamera>& camera);

		/**
		 * @brief 结束一个2D场景
		 */
		static void EndScene();

		/**
		 * @brief 绘制矩形（无深度）
		 * @param position 坐标（x，y）
		 * @param size 尺寸
		 * @param color 颜色
		 * @note z坐标为0
		 */
		static void DrawRectangle(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		/**
		 * @brief 绘制矩形（有深度）
		 * @param position 坐标（x，y，z）
		 * @param size 尺寸
		 * @param color 颜色
		 */
		static void DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
	};
}

#endif