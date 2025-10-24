/**
 * @file Platform/OpenGL/ImguiOpengl.h
 * @author Imgui
 * @modifier LinhengXilan
 * @date 2025-10-24
 * @version build16
 * 
 * @brief Imgui的OpenGL头文件
 */

#pragma once
#include <imgui/imgui.h>      // IMGUI_IMPL_API
#ifndef IMGUI_DISABLE

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_Init(const char* glsl_version = nullptr);
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_Shutdown();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_NewFrame();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);

// (Optional) Called by Init/NewFrame/Shutdown
IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_CreateDeviceObjects();
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_DestroyDeviceObjects();

// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
IMGUI_IMPL_API void     ImGui_ImplOpenGL3_UpdateTexture(ImTextureData* tex);

// Configuration flags to add in your imconfig file:
//#define IMGUI_IMPL_OPENGL_ES2     // Enable ES 2 (Auto-detected on Emscripten)
//#define IMGUI_IMPL_OPENGL_ES3     // Enable ES 3 (Auto-detected on iOS/Android)

// You can explicitly select GLES2 or GLES3 API by using one of the '#define IMGUI_IMPL_OPENGL_LOADER_XXX' in imconfig.h or compiler command-line.
#if !defined(IMGUI_IMPL_OPENGL_ES2) \
 && !defined(IMGUI_IMPL_OPENGL_ES3)

#endif

#endif // #ifndef IMGUI_DISABLE