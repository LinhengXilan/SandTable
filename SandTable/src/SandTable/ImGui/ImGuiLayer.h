/**
 * @file SandTable/ImGui/ImguiLayer.h
 * @author LinhengXilan
 * @date 2025-10-24
 * @version build16
 * 
 * @brief Imgui层
 */

#ifndef SANDTABLE_IMGUI_IMGUILAYER_H
#define SANDTABLE_IMGUI_IMGUILAYER_H

#include <SandTable/Layer.h>
#include <SandTable/Events/Keyboard.h>
#include <SandTable/Events/Mouse.h>
#include <SandTable/Events/Application.h>

namespace SandTable
{
	class SANDTABLE_DLL ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void Begin();
		void End();
		void Attach() override;
		void Detach() override;
		void ImguiRender() override;

	private:
		//float m_Time = 0.0f;
	};
}

#endif