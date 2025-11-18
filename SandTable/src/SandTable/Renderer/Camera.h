/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief 照相机头文件
 */

#ifndef SANDTABLE_RENDERER_CAMERA_H
	#define SANDTABLE_RENDERER_CAMERA_H

#include <SandTable/Core.h>
#include <glm/glm.hpp>
#include <SandTable/Core/Clock.h>

namespace SandTable
{

	enum class CameraType : unsigned char
	{
		Normal, Orthographic
	};
	/**
	 * @brief 摄像机类
	 */
	class Camera
	{
	public:
		Camera() = default;
		virtual ~Camera() = default;

	public:
		virtual const CameraType GetCameraType() const = 0;
		virtual const glm::mat4& GetViewMatrix() const = 0;
		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void SetProjectionMatrix(float left, float right, float bottom, float top) = 0;
		virtual void SetProjectionMatrix(float aspectRatio, float zoomRatio) = 0;

		virtual void RecalculateViewMatrix(const glm::vec3& position, const float rotation) = 0;

		static ObjectRef<Camera> Create();
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera() = default;
		virtual ~OrthographicCamera() = default;

	public:
		static ObjectRef<OrthographicCamera> Create(float left, float right, float bottom, float top);
		static ObjectRef<OrthographicCamera> Create(float aspectRatio, float zoomRatio);
	};
}

#endif