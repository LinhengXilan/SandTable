/**
 * @file SandTable/Renderer/RendererAPI.cpp
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief
 */

#include <pch.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <SandTable/Log.h>

namespace SandTable
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	RendererAPI::API RendererAPI::GetAPI()
	{
		switch (s_API)
		{
			case API::None:
				SANDTABLE_CORE_ASSERT(false, "RendererAPI is currently not supported!");
				return s_API;
			case API::OpenGL:
				SANDTABLE_CORE_INFO("Current RendererAPI: OpenGL");
				return s_API;
			case API::DirectX:
				SANDTABLE_CORE_INFO("Current RendererAPI: DirectX");
				return s_API;
			default:
				SANDTABLE_CORE_ASSERT(false, "Unknown RendererAPI!");
				return s_API;
		}
	}
}