/**
 * @file Platform/OpenGL/OpenGLTexture.cpp
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief OpenGL纹理
 */

#include <pch.h>
#include <Platform/OpenGL/OpenGLTexture.h>
#include <glad/gl.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <SandTable/Core/Log.h>

namespace SandTable
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: m_Path(path)
	{
		int channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &m_Width, &m_Height, &channels, 0);
		SANDTABLE_CORE_ASSERT(data, "Failed to load texture!");
		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGBA8, m_Width, m_Height);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}

	int32_t OpenGLTexture2D::GetWidth() const
	{
		return m_Width;
	}

	int32_t OpenGLTexture2D::GetHeight() const
	{
		return m_Height;
	}
}