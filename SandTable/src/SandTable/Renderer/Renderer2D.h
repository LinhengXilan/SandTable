/**
 * @file SandTable/Renderer/Renderer2D.h
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 * 
 * @brief 2D渲染器
 */

#ifndef SANDTABLE_RENDERER_RENDERER2D_H
#define SANDTABLE_RENDERER_RENDERER2D_H

#include <SandTable/Renderer/Camera.h>
#include <glm/glm.hpp>
#include <SandTable/Renderer/VertexArray.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/Texture.h>

namespace SandTable
{
	struct Renderer2DData
	{
		ObjectRef<VertexArray> VertexArray;
		ObjectRef<Shader> Shader2D;
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
		 * @brief 绘制矩形
		 * @param position 坐标
		 * @param size 尺寸
		 * @param color 颜色
		 * @param texture 纹理贴图
		 * @param tilingFactor 纹理平铺系数
		 * @param tintcolor 纹理染色
		 * @note 颜色和纹理混合
		 */
		static void DrawRectangle(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawRectangle(const glm::vec2& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRectangle(const glm::vec3& position, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRectangle(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f);

		/**
		 * @brief 绘制有角度的矩形
		 * @param position 坐标
		 * @param rotation 旋转角度
		 * @param size 尺寸
		 * @param color 颜色
		 * @param texture 纹理贴图
		 * @param tilingFactor 纹理平铺系数
		 * @param tintcolor 纹理染色
		 * @note 颜色和纹理混合
		 */
		static void DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& color);
		static void DrawRotatedRectangle(const glm::vec2& position, float rotation, const glm::vec2& size, const glm::vec4& color);
		static void DrawRotatedRectangle(const glm::vec2& position, float rotation, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedRectangle(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& color, const ObjectRef<Texture2D>& texture, float tilingFactor = 1.0f);
	};
}

#endif