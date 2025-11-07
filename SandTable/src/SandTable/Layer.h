/**
 * @file SandTable/Layer.h
 * @author LinhengXilan
 * @date 2025-11-7
 * @version build25
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
	public :
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void Attach();
		virtual void Detach();
		virtual void OnUpdate(TimeStep timeStep);

		virtual void ImguiRender();
		virtual void OnEvent(Event& event);
		
		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}

#endif