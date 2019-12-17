//
//  main.cpp
//  opengl-bunny
//
//  Created by vtta on 12/16/19.
//  Copyright © 2019 vtta. All rights reserved.
//

#include <glad/glad.h>
// NOLINT
#include <GLFW/glfw3.h>

#include <array>
#include <iostream>

#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "Tests.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "imgui.h"
// NOLINT
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main(int argc, const char *argv[]) {
    auto window = GLInit();
    ASSERT(window != nullptr);

    Renderer render;

    ImGui::CreateContext();
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410 core");

    test::ClearColor test;

    do {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        test.onUpdate(0.0f);
        test.onRender();
        test.onImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
        render.clear();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
    // Check if the ESC or Q key was pressed or the window was closed

    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}
