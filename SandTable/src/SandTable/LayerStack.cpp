/**
 * @file SandTable/LayerStack.cpp
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief 图层栈实现
 */

#include <pch.h>

#include <SandTable/LayerStack.h>

namespace SandTable
{
	void LayerStack::PushLayer(ObjectRef<Layer>& layer)
	{
		m_Layers.push_back(layer);
		m_LayerInsertIndex++;
		layer->Attach();
	}

	void LayerStack::PushOverlay(ObjectRef<Layer>& overlay)
	{
		m_Layers.push_back(overlay);
		overlay->Attach();
	}

	void LayerStack::PopLayer(ObjectRef<Layer>& layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
			layer->Detach();
		}
	}

	void LayerStack::PopOverlay(ObjectRef<Layer>& overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			overlay->Detach();
		}
	}
}