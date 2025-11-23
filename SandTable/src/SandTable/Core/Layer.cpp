/**
 * @file SandTable/Layer.cpp
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 图层实现
 */

#include <pch.h>

#include <SandTable/Core/Layer.h>

namespace SandTable
{
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{

	}

	void Layer::Attach()
	{

	}

	void Layer::Detach()
	{

	}

	const std::string& Layer::GetName() const
	{
		return m_DebugName;
	}

	void Layer::OnUpdate(TimeStep timeStep)
	{

	}

	void Layer::ImguiRender()
	{

	}

	void Layer::OnEvent(Event& event)
	{

	}

}