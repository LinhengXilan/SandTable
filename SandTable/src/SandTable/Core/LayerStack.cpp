/**
 * @file SandTable/LayerStack.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 图层栈实现
 */

#include <pch.h>

#include <SandTable/Core/LayerStack.h>

namespace SandTable
{
	LayerStack::~LayerStack()
	{
		for (auto layer : m_Layers)
		{
			if (layer->GetName() != "ImguiLayer")
			{
				layer->Detach();
			}
		}
	}

	void LayerStack::PushLayer(const ObjectRef<Layer>& layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(const ObjectRef<Layer>& overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(const ObjectRef<Layer>& layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.end())
		{
			layer->Detach();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(const ObjectRef<Layer>& overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->Detach();
			m_Layers.erase(it);
		}
	}

	std::vector<ObjectRef<Layer>>::iterator LayerStack::begin()
	{
		return m_Layers.begin();
	}

	std::vector<ObjectRef<Layer>>::iterator LayerStack::end()
	{
		return m_Layers.end();
	}

	std::vector<ObjectRef<Layer>>::const_iterator LayerStack::begin() const
	{
		return m_Layers.begin();
	}

	std::vector<ObjectRef<Layer>>::const_iterator LayerStack::end() const
	{
		return m_Layers.end();
	}

	std::vector<ObjectRef<Layer>>::reverse_iterator LayerStack::rbegin()
	{
		return m_Layers.rbegin();
	}

	std::vector<ObjectRef<Layer>>::reverse_iterator LayerStack::rend()
	{
		return m_Layers.rend();
	}

	std::vector<ObjectRef<Layer>>::const_reverse_iterator LayerStack::rbegin() const
	{
		return m_Layers.rbegin();
	}

	std::vector<ObjectRef<Layer>>::const_reverse_iterator LayerStack::rend() const
	{
		return m_Layers.rend();
	}
}