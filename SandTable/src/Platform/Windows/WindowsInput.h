/**
 * @file Platform/Windows/WindowsInput.h
 * @author LinhengXilan
 * @date 2025-9-20
 * @version build13
 */

#ifndef PLATFORM_WINDOWS_WINDOWSINPUT_H
#define PLATFORM_WINDOWS_WINDOWSINPUT_H

#include <pch.h>
#include <SandTable/Input.h>

namespace SandTable
{
	class SANDTABLE_DLL WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMousePressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePosImpl() override;
		virtual float GetMousePosXImpl() override;
		virtual float GetMousePosYImpl() override;
	};
}

#endif