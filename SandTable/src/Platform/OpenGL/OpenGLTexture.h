/**
 * @file Platform/OpenGL/OpenGLTexture.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
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
		~OpenGLTexture2D() override;

	public:
		int32_t GetWidth() const override;
		int32_t GetHeight() const override;

		void Bind(uint32_t slot = 0) const override;

	private:
		std::string m_Path;
		int32_t m_Width;
		int32_t m_Height;
		uint32_t m_RendererID;
	};
}

#endif