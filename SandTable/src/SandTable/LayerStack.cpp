/**
 * @file SandTable/LayerStack.cpp
 * @author LinhengXilan
 * @date 2025-10-26
 * @version build19
 * 
 * @brief 图层栈实现
 */

#include <pch.h>

#include <SandTable/LayerStack.h>

namespace SandTable
{
	LayerStack::LayerStack()
	{

	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
		layer->Attach();
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->Attach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
			layer->Detach();
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			overlay->Detach();
		}
	}
}