/**
 * @file SandTable/ImGui/ImguiLayer.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @brief Imgui层
 */

#ifndef SANDTABLE_IMGUI_IMGUILAYER_H
#define SANDTABLE_IMGUI_IMGUILAYER_H

#include <SandTable/Layer.h>
#include <SandTable/Events/Keyboard.h>
#include <SandTable/Events/MouseEvent.h>
#include <SandTable/Events/ApplicationEvent.h>

namespace SandTable
{
	class SANDTABLE_DLL ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer() override = default;

	public:
		void Begin() override;
		void End() override;
		void Attach() override;
		void Detach() override;
		void ImguiRender() override;
	};
}

#endif