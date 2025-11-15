/**
 * @file SandTable/Input.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
		static float GetMousePosX() { return s_Instance->GetMousePosXImpl(); }
		static float GetMousePosY() { return s_Instance->GetMousePosYImpl(); }
		static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		static bool IsMousePressed(int button) { return s_Instance->IsMousePressedImpl(button); }

	protected:
		virtual const float GetMousePosXImpl() = 0;
		virtual const float GetMousePosYImpl() = 0;
		virtual const std::pair<float, float> GetMousePosImpl() = 0;
		virtual const bool IsKeyPressedImpl(int keycode) = 0;
		virtual const bool IsMousePressedImpl(int button) = 0;

	private:
		static Input* s_Instance;
	};
}

#endif