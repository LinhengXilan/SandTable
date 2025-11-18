/**
 * @file SandTable.h
 * @author LinhengXilan
 * @version build33
 * @date 2025-11-18
 * 
 * @breif SandTable主头文件
 */

#ifndef SANDTABLE_H
#define SANDTABLE_H

// 程序基本系统
#include <SandTable/Application.h>
#include <SandTable/Layer.h>
#include <SandTable/Core/Clock.h>
#include <SandTable/Log.h>

// 输入输出
#include <SandTable/KeyCode.h>
#include <SandTable/MouseCode.h>
#include <SandTable/Input.h>
#include <SandTable/CameraController.h>

// 图形渲染
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <SandTable/Renderer/Camera.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/Texture.h>

// 程序入口点
#include <SandTable/EntryPoint.h>

#endif