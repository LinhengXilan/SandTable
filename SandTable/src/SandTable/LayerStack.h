/**
 * @file SandTable/LayerStack.h
 * @author LinhengXilan
 * @version build29
 * @date 2025-11-12
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
		LayerStack();
		~LayerStack();

	public:
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}

#endif