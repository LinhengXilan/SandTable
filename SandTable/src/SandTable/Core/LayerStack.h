/**
 * @file SandTable/LayerStack.h
 * @author LinhengXilan
 * @version build34
 * @date 2025-11-22
 * 
 * @brief 图层栈头文件
 */

#ifndef SANDTABLE_LAYERSTACK_H
#define SANDTABLE_LAYERSTACK_H

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
		void PushLayer(const ObjectRef<Layer>& layer);
		void PushOverlay(const ObjectRef<Layer>& overlay);
		void PopLayer(const ObjectRef<Layer>& layer);
		void PopOverlay(const ObjectRef<Layer>& overlay);

		std::vector<ObjectRef<Layer>>::iterator begin();
		std::vector<ObjectRef<Layer>>::iterator end();
		std::vector<ObjectRef<Layer>>::const_iterator begin() const;
		std::vector<ObjectRef<Layer>>::const_iterator end() const;
		std::vector<ObjectRef<Layer>>::reverse_iterator rbegin();
		std::vector<ObjectRef<Layer>>::reverse_iterator rend();
		std::vector<ObjectRef<Layer>>::const_reverse_iterator rbegin() const;
		std::vector<ObjectRef<Layer>>::const_reverse_iterator rend() const;

	private:
		std::vector<ObjectRef<Layer>> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}

#endif