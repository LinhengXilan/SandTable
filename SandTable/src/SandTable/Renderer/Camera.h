/**
 * @file SandTable/Renderer/Camera.h
 * @author LinhengXilan
 * @date 2025-11-2
 * @version build23
 * 
 * @brief 照相机头文件
 */

#ifndef SANDTABLE_RENDERER_CAMERA_H
	#define SANDTABLE_RENDERER_CAMERA_H

#include <glm/glm.hpp>

namespace SandTable
{
	enum class Type : unsigned char
	{
		Normal, Orthographic
	};
	/**
	 * @brief 摄像机类
	 */
	class Camera
	{
	public:
		virtual ~Camera() = default;

		virtual void SetPosition(const glm::vec3& position) = 0;
		virtual void SetRotation(const float& rotation) = 0;

		inline virtual const glm::vec3& GetPosition() const = 0;
		inline virtual const float& GetRotation() const = 0;
		inline virtual const glm::mat4& GetViewMatrix() const = 0;
		inline virtual const glm::mat4& GetProjectionMatrix() const = 0;
		inline virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void RecalculateViewMatrix() = 0;
		virtual void OnUpdate() = 0;

		static Camera* Create();
	};

	class OrthographicCamera
	{
	public:
		virtual ~OrthographicCamera() = default;

		virtual void SetPosition(const glm::vec3& position) = 0;
		virtual void SetRotation(const float& rotation) = 0;

		inline virtual const glm::vec3& GetPosition() const = 0;
		inline virtual const float& GetRotation() const = 0;
		inline virtual const glm::mat4& GetViewMatrix() const = 0;
		inline virtual const glm::mat4& GetProjectionMatrix() const = 0;
		inline virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

		virtual void RecalculateViewMatrix() = 0;
		virtual void OnUpdate() = 0;

		static OrthographicCamera* Create(float left = 0, float right = 0, float bottom = 0, float top = 0);
	};
}

#endif