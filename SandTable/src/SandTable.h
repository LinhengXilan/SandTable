/**
 * @file SandTable.h
 * @author LinhengXilan
 * @version build39
 * @date 2025-11-29
 * 
 * @breif SandTable主头文件
 */

#ifndef SANDTABLE_H
#define SANDTABLE_H

// 程序基本系统
#include <SandTable/Core/Core.h>
#include <SandTable/Core/Application.h>
#include <SandTable/Core/Layer.h>
#include <SandTable/Core/Log.h>

// Debug
#include <SandTable/Debug/Instrumentor.h>

// 时钟
#include <SandTable/Core/Timer/Clock.h>
#include <SandTable/Core/Timer/Timer.h>

// 输入输出
#include <SandTable/Core/KeyCode.h>
#include <SandTable/Core/MouseCode.h>
#include <SandTable/Core/Input.h>

#include <SandTable/CameraController.h>

// 图形渲染
#include <SandTable/ImGui/ImguiLayer.h>
#include <SandTable/Renderer/Renderer.h>
#include <SandTable/Renderer/Renderer2D.h>
#include <SandTable/Renderer/RenderCommand.h>
#include <SandTable/Renderer/Camera.h>
#include <SandTable/Renderer/Shader.h>
#include <SandTable/Renderer/Texture.h>

#endif