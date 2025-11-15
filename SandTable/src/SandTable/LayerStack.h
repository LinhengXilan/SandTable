/**
 * @file SandTable/LayerStack.h
 * @author LinhengXilan
 * @version build32
 * @date 2025-11-15
 * 
 * @brief 图层栈头文件
 */

#ifndef SANDTABLE_LAYERSTACK_H
#define SANDTABLE_LAYERSTACK_H

#include <SandTable/Core.h>
#include <SandTable/Layer.h>

namespace SandTable
{
	class SANDTABLE_DLL LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack() = default;

	public:
		void PushLayer(ObjectRef<Layer>& layer);
		void PushOverlay(ObjectRef<Layer>& overlay);
		void PopLayer(ObjectRef<Layer>& layer);
		void PopOverlay(ObjectRef<Layer>& overlay);

		std::vector<ObjectRef<Layer>>::iterator begin() { return m_Layers.begin(); }
		std::vector<ObjectRef<Layer>>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<ObjectRef<Layer>> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}

#endif