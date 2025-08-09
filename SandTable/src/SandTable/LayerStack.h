/**
 * @file SandTable/LayerStack.h
 * @author LinhengXilan
 * @date 2025-8-9
 * @version build9
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}

#endif