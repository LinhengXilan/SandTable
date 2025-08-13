/**
 * @file SandTable/ImGui/ImGuiLayer.h
 * @author LinhengXilan
 * @date 2025-8-14
 * @version build12
 */

#ifndef SANDTABLE_IMGUI_IMGUILAYER_H
#define SANDTABLE_IMGUI_IMGUILAYER_H

#include <SandTable/Layer.h>
#include <SandTable/Events/Keyboard.h>
#include <SandTable/Events/Mouse.h>
#include <SandTable/Events/Application.h>

namespace SandTable
{
	class SANDTABLE_DLL ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void Update() override;
		void OnEvent(Event& event) override;
		void Attach() override;
		void Detach() override;

	private:
		bool OnMousePressed(MousePressed& event);
		bool OnMouseReleased(MouseReleased& event);
		bool OnMouseMoved(MouseMoved& event);
		bool OnMouseScrolled(MouseScrolled& event);
		bool OnWindowResize(WindowResize& event);
		bool OnKeyPressed(KeyPressed& event);
		bool OnKeyReleased(KeyReleased& event);
		bool OnKeyTyped(KeyTyped& event);

	private:
		float m_Time = 0.0f;
	};
}

#endif