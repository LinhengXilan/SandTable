/**
 * @file SandTable/Layer.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief 图层头文件
 */

#ifndef SANDTABLE_LAYER_H
#define SANDTABLE_LAYER_H

#include <SandTable/Core.h>
#include <SandTable/Events/Event.h>
#include <SandTable/Core/Clock.h>

namespace SandTable
{
	class SANDTABLE_DLL Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

	public:
		const std::string& GetName() const;

		virtual void Begin();
		virtual void End();
		virtual void Attach();
		virtual void Detach();
		virtual void ImguiRender();
		virtual void OnUpdate(TimeStep timeStep);
		virtual void OnEvent(Event& event);
		
	protected:
		std::string m_DebugName;
	};
}

#endif