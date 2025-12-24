/**
 * @file SandTable/Core/LayerStack.h
 * @author LinhengXilan
 * @version build41
 * @date 2025-12-25
 * 
 * @brief 图层栈头文件
 */

#ifndef SANDTABLE_CORE_LAYERSTACK_H
#define SANDTABLE_CORE_LAYERSTACK_H

#include <SandTable/Core/Core.h>
#include <SandTable/Core/Layer.h>

namespace SandTable
{
	class SANDTABLE_DLL LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

	public:
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin();
		std::vector<Layer*>::iterator end();
		std::vector<Layer*>::const_iterator begin() const;
		std::vector<Layer*>::const_iterator end() const;
		std::vector<Layer*>::reverse_iterator rbegin();
		std::vector<Layer*>::reverse_iterator rend();
		std::vector<Layer*>::const_reverse_iterator rbegin() const;
		std::vector<Layer*>::const_reverse_iterator rend() const;

	private:
		std::vector<Layer*> m_Layers;
		uint32_t m_LayerInsertIndex = 0;
	};
}

#endif