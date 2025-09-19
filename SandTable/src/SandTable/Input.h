/**
 * @file SandTable/Input.h
 * @author LinhengXilan
 * @date 2025-9-20
 * @version build13
 */

#ifndef SANDTABLE_INPUT_H
#define SANDTABLE_INPUT_H

#include <SandTable/Core.h>

namespace SandTable
{
	class SANDTABLE_DLL Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMousePressed(int button) { return s_Instance->IsMousePressedImpl(button); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		inline static float GetMousePosX() { return s_Instance->GetMousePosXImpl(); }
		inline static float GetMousePosY() { return s_Instance->GetMousePosYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMousePressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual float GetMousePosXImpl() = 0;
		virtual float GetMousePosYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}

#endif