/**
 * @file SandTable/Renderer/Texture.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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

		virtual void Bind(uint32_t slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		Texture2D() = default;
		virtual ~Texture2D() = default;

	public:
		static ObjectRef<Texture2D> Create(const std::string& path);
	};
}

#endif