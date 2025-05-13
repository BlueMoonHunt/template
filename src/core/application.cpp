#include "application.h"
#include <raylib.h>

Application* Application::s_instance = nullptr;

Application::Application(const ApplicationSpecification& specs)
    : m_Specs(specs) {
    s_instance = this;
    init();
}

Application::~Application() {
    shutdown();
}

void Application::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Color{ 25,25,25,255 });

        

        EndDrawing();
    }
}

void Application::init() {

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(m_Specs.width, m_Specs.height, m_Specs.name);
    SetTargetFPS(60);
}

void Application::shutdown() {
    CloseWindow();
}
