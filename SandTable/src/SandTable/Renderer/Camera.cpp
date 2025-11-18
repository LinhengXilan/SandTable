/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief 照相机头文件
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Renderer/Camera.h>
#include <Platform/OpenGL/OpenGLCamera.h>

namespace SandTable
{
	ObjectRef<Camera> Camera::Create()
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
			return nullptr;
		default:
			return nullptr;
		}
	}

	ObjectRef<OrthographicCamera> OrthographicCamera::Create(float left, float right, float bottom, float top)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLOrthographicCamera>(left, right, bottom, top);
		default:
			return nullptr;
		}
	}

	ObjectRef<OrthographicCamera> OrthographicCamera::Create(float aspectRatio, float zoomRatio)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLOrthographicCamera>(aspectRatio, zoomRatio);
		default:
			return nullptr;
		}
	}
}