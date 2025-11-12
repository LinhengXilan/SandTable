/**
 * @file SandTable/Input.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef SANDTABLE_INPUT_H
#define SANDTABLE_INPUT_H

#include <SandTable/Core.h>

namespace SandTable
{
	class SANDTABLE_DLL Input
	{
	public:
		Input() = default;
		virtual ~Input() = default;

	public:
		inline static float GetMousePosX() { return s_Instance->GetMousePosXImpl(); }
		inline static float GetMousePosY() { return s_Instance->GetMousePosYImpl(); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMousePressed(int button) { return s_Instance->IsMousePressedImpl(button); }

	protected:
		virtual inline const float GetMousePosXImpl() = 0;
		virtual inline const float GetMousePosYImpl() = 0;
		virtual inline const std::pair<float, float> GetMousePosImpl() = 0;
		virtual inline const bool IsKeyPressedImpl(int keycode) = 0;
		virtual inline const bool IsMousePressedImpl(int button) = 0;

	private:
		static Input* s_Instance;
	};
}

#endif