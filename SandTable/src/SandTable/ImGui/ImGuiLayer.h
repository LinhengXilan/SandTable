/**
 * @file SandTable/ImGui/ImGuiLayer.h
 * @author LinhengXilan
 * @date 2025-8-12
 * @version build11
 */

#ifndef SANDTABLE_IMGUI_IMGUILAYER_H
#define SANDTABLE_IMGUI_IMGUILAYER_H

#include <SandTable/Layer.h>

namespace SandTable
{
	class SANDTABLE_DLL ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void Update();
		void OnEvent(Event& event);
		void Attach();
		void Detach();

	private:
		float m_Time = 0.0f;
	};
}

#endif