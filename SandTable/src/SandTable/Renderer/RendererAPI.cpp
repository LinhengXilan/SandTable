/**
 * @file SandTable/Renderer/RendererAPI.cpp
 * @author LinhengXilan
 * @date 2025-11-5
 * @version build24
 * 
 * @brief
 */

#include <pch.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <SandTable/Log.h>

namespace SandTable
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
	bool RendererAPI::s_IsAPIInitialized = false;

	RendererAPI::API RendererAPI::GetAPI()
	{
		switch (s_API)
		{
		case API::None:
			if (s_IsAPIInitialized == false)
			{
				SANDTABLE_CORE_ASSERT(false, "RendererAPI is currently not supported!");
				s_IsAPIInitialized = true;
			}
			return s_API;
		case API::OpenGL:
			[[unlikely]]
			if (s_IsAPIInitialized == false)
			{
				SANDTABLE_CORE_INFO("Current RendererAPI: OpenGL");
				s_IsAPIInitialized = true;
			}
			return s_API;
			case API::DirectX:
			[[unlikely]]
			if (s_IsAPIInitialized == false)
			{
				SANDTABLE_CORE_INFO("Current RendererAPI: DirectX");
				s_IsAPIInitialized = true;
			}
			return s_API;
		default:
			[[unlikely]]
			if (s_IsAPIInitialized == false)
			{
				SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
				s_IsAPIInitialized = true;
			}
			return s_API;
		}
	}
}