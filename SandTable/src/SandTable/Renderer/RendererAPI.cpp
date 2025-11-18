/**
 * @file SandTable/Renderer/RendererAPI.cpp
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief 
 */

#include <pch.h>
#include <SandTable/Renderer/RendererAPI.h>
#include <SandTable/Log.h>

namespace SandTable
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::None;

	void RendererAPI::SetAPI(API api)
	{
		switch (api)
		{
		case API::None:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI is not selected!");
			break;
		case API::OpenGL:
		case API::OpenGL3:
			SANDTABLE_CORE_INFO("Current RendererAPI: OpenGL");
			break;
		case API::DirectX:
			SANDTABLE_CORE_INFO("Current RendererAPI: DirectX");
			break;
		default:
			SANDTABLE_CORE_ASSERT(false, "RendererAPI is currently not supported!");
			break;
		}
		s_API = api;
	}

	RendererAPI::API RendererAPI::GetAPI()
	{
		return s_API;
	}
}