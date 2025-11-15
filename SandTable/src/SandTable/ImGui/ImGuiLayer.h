/**
 * @file SandTable/ImGui/ImguiLayer.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief Imgui层
 */

#ifndef SANDTABLE_IMGUI_IMGUILAYER_H
#define SANDTABLE_IMGUI_IMGUILAYER_H

#include <SandTable/Layer.h>
#include <SandTable/Events/Keyboard.h>
#include <SandTable/Events/Mouse.h>
#include <SandTable/Events/ApplicationEvent.h>

namespace SandTable
{
	class SANDTABLE_DLL ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

	public:
		void Begin() override;
		void End() override;
		void Attach() override;
		void Detach() override;
		void ImguiRender() override;
	};
}

#endif