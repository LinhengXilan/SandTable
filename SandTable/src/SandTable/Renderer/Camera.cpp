/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 * 
 * @brief 相机接口
 */

#include <pch.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Renderer/Camera.h>
#include <Platform/OpenGL/OpenGLCamera.h>

namespace SandTable
{
	ObjectRef<Camera> Camera::Create(CameraType type, float left, float right, float bottom, float top)
	{
		switch (type)
		{
		case CameraType::Normal:
			switch (Renderer::GetRendererAPI())
			{
			case RendererAPI::API::None:
				return nullptr;
			case RendererAPI::API::OpenGL:
				return nullptr;
			default:
				return nullptr;
			}
		case CameraType::Orthographic:
			return OrthographicCamera::Create(left, right, bottom, top);
		}
		
		
	}

	ObjectRef<OrthographicCamera> OrthographicCamera::Create(float left, float right, float bottom, float top)
	{
		switch (Renderer::GetRendererAPI())
		{
		case RendererAPI::API::None:
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateObjectRef<OpenGLOrthographicCamera>(left, right, bottom, top);
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
			return CreateObjectRef<OpenGLOrthographicCamera>(aspectRatio, zoomRatio);
		default:
			return nullptr;
		}
	}
}