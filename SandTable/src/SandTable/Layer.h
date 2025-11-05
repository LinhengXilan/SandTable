/**
 * @file SandTable/Layer.h
 * @author LinhengXilan
 * @date 2025-11-5
 * @version build24
 * 
 * @brief 图层头文件
 */

#ifndef SANDTABLE_LAYER_H
#define SANDTABLE_LAYER_H

#include <SandTable/Core.h>
#include <SandTable/Events/Event.h>

namespace SandTable
{
	class SANDTABLE_DLL Layer
	{
	public :
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void Attach();
		virtual void Detach();
		virtual void OnUpdate();

		virtual void ImguiRender();
		virtual void OnEvent(Event& event);
		
		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}

#endif