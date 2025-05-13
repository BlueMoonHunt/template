#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include "core/application.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    Application* app = new Application(ApplicationSpecification{
        .name = "APP-NAME",
        .width = 900,
        .height = 500,
    });

    *appstate = app;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    Application* app = static_cast<Application*>(appstate);

    app->onUpdate();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    Application* app = static_cast<Application*>(appstate);

    if (event->type == SDL_EVENT_QUIT)
        return SDL_APP_SUCCESS;

    app->onEvent(event);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    Application* app = static_cast<Application*>(appstate);

    delete app;

    
    SDL_Quit();
}