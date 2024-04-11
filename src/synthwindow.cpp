#include "synthwindow.h"

void ShowSynthWindow(){

    IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing Dear ImGui context. Refer to examples app!");
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::Begin("gsynth (debug)");
    struct Funcs
    {
        static float Sin(void*, int i) { return sinf(i * 0.1f); }
        static float Saw(void*, int i) { return (i & 1) ? 1.0f : -1.0f; }
    };
    static int func_type = 0, display_count = 70;
    ImGui::SeparatorText("Functions");
    ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
    ImGui::Combo("func", &func_type, "Sin\0Saw\0");
    ImGui::SameLine();
    ImGui::SliderInt("Sample count", &display_count, 1, 400);
    float (*func)(void*, int) = (func_type == 0) ? Funcs::Sin : Funcs::Saw;
    ImGui::PlotLines("Lines", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();
}