/**
 * @file Platform/OpenGL/ImGuiOpenGLRenderer.h
 * @author LinhengXilan
 * @date 2025-8-14
 * @version build12
 */

#ifndef PLATFORM_OPENGL_IMGUIOPENGLRENDERER_H
#define PLATFORM_OPENGL_IMGUIOPENGLRENDERER_H

#include <imgui.h>

#ifndef IMGUI_DISABLE

IMGUI_IMPL_API bool ImGui_ImplOpenGL3_Init(const char* glsl_version = nullptr);
IMGUI_IMPL_API void ImGui_ImplOpenGL3_Shutdown();
IMGUI_IMPL_API void ImGui_ImplOpenGL3_NewFrame();
IMGUI_IMPL_API void ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);
IMGUI_IMPL_API bool ImGui_ImplOpenGL3_CreateDeviceObjects();
IMGUI_IMPL_API void ImGui_ImplOpenGL3_DestroyDeviceObjects();
IMGUI_IMPL_API void ImGui_ImplOpenGL3_UpdateTexture(ImTextureData* tex);

#endif

#endif