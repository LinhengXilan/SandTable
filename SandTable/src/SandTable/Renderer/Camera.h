/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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
		enum class Direction : unsigned char
		{
			Up, Down,
			Left, Right,
			Forward, Backward,
			clockwise, counterclockwise
		};
	public:
		Camera() = default;
		virtual ~Camera() = default;

	public:
		inline virtual const CameraType GetCameraType() const = 0;
		inline virtual const glm::vec3& GetPosition() const = 0;
		inline virtual const float GetRotation() const = 0;
		inline virtual const glm::mat4& GetViewMatrix() const = 0;
		inline virtual const glm::mat4& GetProjectionMatrix() const = 0;
		inline virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void SetPosition(const glm::vec3& position) = 0;
		virtual void SetRotation(const float rotation) = 0;
		virtual void SetMoveSpeed(const float speed) = 0;
		virtual void SetRotateSpeed(const float speed) = 0;

		virtual void RecalculateViewMatrix() = 0;

		virtual void Move(Direction direction) = 0;
		virtual void Move(Direction direction, TimeStep timeStep) = 0;
		virtual void Move(Direction direction, float speed) = 0;
		virtual void Move(Direction direction, float speed, TimeStep timeStep) = 0;
		virtual void Rotate(Direction direction) = 0;
		virtual void Rotate(Direction direction, TimeStep timeStep) = 0;
		virtual void Rotate(Direction direction, float speed) = 0;
		virtual void Rotate(Direction direction, float speed, TimeStep timeStep) = 0;

		static ObjectRef<Camera> Create();
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera() = default;
		virtual ~OrthographicCamera() = default;

	public:
		static ObjectRef<OrthographicCamera> Create(float left = 0, float right = 0, float bottom = 0, float top = 0);
	};
}

#endif