/**
 * @file Platform/Windows/WindowsInput.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
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
		const bool IsKeyPressedImpl(int keycode) override;
		const bool IsMousePressedImpl(int button) override;
		const std::pair<float, float> GetMousePosImpl() override;
		const float GetMousePosXImpl() override;
		const float GetMousePosYImpl() override;
	};
}

#endif