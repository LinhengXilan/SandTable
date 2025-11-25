/**
 * @file Platform/Windows/WindowsInput.h
 * @author LinhengXilan
 * @version build37
 * @date 2025-11-25
 */

#ifndef PLATFORM_WINDOWS_WINDOWSINPUT_H
#define PLATFORM_WINDOWS_WINDOWSINPUT_H

#include <pch.h>
#include <SandTable/Core/Input.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowsInput : public Input
	{
	public:
		WindowsInput() = default;
		~WindowsInput() override = default;

	protected:
		bool IsKeyPressedImpl(int keycode) override;
		bool IsMousePressedImpl(int button) override;
		std::pair<float, float> GetMousePosImpl() override;
		float GetMousePosXImpl() override;
		float GetMousePosYImpl() override;
	};
}

#endif