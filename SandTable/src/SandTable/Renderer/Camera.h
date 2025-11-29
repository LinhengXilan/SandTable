/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @brief 相机接口
 */

#ifndef SANDTABLE_RENDERER_CAMERA_H
	#define SANDTABLE_RENDERER_CAMERA_H

#include <SandTable/Core/Core.h>
#include <glm/glm.hpp>
#include <SandTable/Core/Timer/Clock.h>

namespace SandTable
{
	/**
	 * @brief 摄像机类
	 */
	class Camera
	{
	public:
		enum class CameraType : uint8_t
		{
			Normal,
			Orthographic
		};
	public:
		Camera() = default;
		virtual ~Camera() = default;

	public:
		virtual CameraType GetCameraType() const = 0;
		virtual const glm::mat4& GetViewMatrix() const = 0;
		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void SetProjectionMatrix(float left, float right, float bottom, float top) = 0;
		virtual void SetProjectionMatrix(float aspectRatio, float zoomRatio) = 0;

		virtual void RecalculateViewMatrix(const glm::vec3& position, float rotation) = 0;

		static ObjectRef<Camera> Create(CameraType type, float left, float right, float bottom, float top);
	};

	/**
	 * @brief 正交相机
	 */
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