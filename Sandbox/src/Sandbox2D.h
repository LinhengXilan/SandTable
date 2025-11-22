/**
 * @file Sandbox2D.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief Sandbox示例程序
 */

#ifndef SANDBOX2D_H
#define SANDBOX2D_H

#include <SandTable.h>

class Sandbox2D : public SandTable::Layer
{
public:
	Sandbox2D();
	~Sandbox2D() override = default;

	void Attach() override;
	void Detach() override;
	void ImguiRender() override;
	void OnUpdate(SandTable::TimeStep timeStep) override;
	void OnEvent(SandTable::Event& event) override;

private:
	SandTable::ObjectRef<SandTable::VertexArray> m_VertexArray;
	SandTable::ObjectRef<SandTable::Shader> m_Shader;
	SandTable::OrthoGraphicCameraController m_CameraController;
	glm::vec4 m_SquareColor = { 1.0f, 0.83f, 0.66f, 1.0f };
};

#endif