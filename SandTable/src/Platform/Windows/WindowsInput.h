/**
 * @file Platform/Windows/WindowsInput.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
 */

#ifndef PLATFORM_WINDOWS_WINDOWSINPUT_H
#define PLATFORM_WINDOWS_WINDOWSINPUT_H

#include <pch.h>
#include <SandTable/Input.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowsInput : public Input
	{
	public:
		WindowsInput() = default;
		~WindowsInput() = default;

	protected:
		virtual inline const bool IsKeyPressedImpl(int keycode) override;
		virtual inline const bool IsMousePressedImpl(int button) override;
		virtual inline const std::pair<float, float> GetMousePosImpl() override;
		virtual inline const float GetMousePosXImpl() override;
		virtual inline const float GetMousePosYImpl() override;
	};
}

#endif