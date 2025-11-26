/**
 * @file SandTable/Renderer/Texture.h
 * @author LinhengXilan
 * @version build38
 * @date 2025-11-26
 * 
 * @brief 纹理
 */

#ifndef SANDTABLE_RENDERER_TEXTURE_H
#define SANDTABLE_RENDERER_TEXTURE_H

#include <SandTable/Core/Core.h>

namespace SandTable
{
	class Texture
	{
	public:
		Texture() = default;
		virtual ~Texture() = default;

	public:
		virtual int32_t GetWidth() const = 0;
		virtual int32_t GetHeight() const = 0;

		virtual void Upload(const void* data, size_t size) const = 0;
		virtual void Bind(uint32_t slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		Texture2D() = default;
		virtual ~Texture2D() = default;

	public:
		/**
		 * @brief 创建一个1x1的白色纹理
		 * @return 白色纹理
		 */
		static ObjectRef<Texture2D> Create();
		/**
		 * @brief 从路径创建一个纹理
		 * @param path 纹理路径
		 * @return 纹理
		 */
		static ObjectRef<Texture2D> Create(const std::string& path);
		/**
		 * @brief 创建指定宽高的空白纹理
		 * @param width 宽
		 * @param height 高
		 * @return 未初始化纹理
		 */
		static ObjectRef<Texture2D> Create(int32_t width, int32_t height);
	};
}

#endif