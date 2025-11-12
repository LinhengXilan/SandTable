/**
 * @file Platform/OpenGL/OpenGLTexture.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 * 
 * @brief OpenGL纹理
 */

#ifndef PLATFORM_OPENGL_OPENGLTEXTURE_H
#define PLATFORM_OPENGL_OPENGLTEXTURE_H

#include <SandTable/Renderer/Texture.h>

namespace SandTable
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();

	public:
		inline const uint32_t GetWidth() const override { return m_Width; }
		inline const uint32_t GetHeight() const override { return m_Height; }

		void Bind(uint32_t slot = 0) const override;

	private:
		std::string m_Path;
		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_RendererID;
	};
}

#endif