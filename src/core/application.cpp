#include "application.h"
#include <SDL3/SDL.h>

Application* Application::s_instance = nullptr;

Application::Application(const ApplicationSpecification& specs)
    : m_Specs(specs) {
    s_instance = this;
    init();
    m_Timstep = 0.0f;
}

Application::~Application() {
    shutdown();
}

void Application::onUpdate() {

    SDL_SetRenderDrawColorFloat(m_Renderer,0.1f,0.1f,0.1f,1.0f);
    SDL_RenderClear(m_Renderer);

    SDL_RenderPresent(m_Renderer);

    static size_t previousTick = SDL_GetTicksNS();
    size_t tick  = SDL_GetTicksNS();
    m_Timstep = (float)(tick - previousTick) / 10e9;
}

void Application::onEvent(SDL_Event* event) {
}


void Application::init() {
    SDL_CreateWindowAndRenderer(m_Specs.name, m_Specs.width, m_Specs.height, SDL_WINDOW_RESIZABLE, &m_Window, &m_Renderer);
}

void Application::shutdown() {
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
}
