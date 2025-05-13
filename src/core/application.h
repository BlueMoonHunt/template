#pragma once
struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;

struct ApplicationSpecification {
    const char* name;
    int width = 0, height = 0;
};

class Application {
public:
    Application(const ApplicationSpecification& specs);
    ~Application();

    static inline Application* Get() { return s_instance; }
    float getTimestep() { return m_Timstep; }
    void onUpdate();
    void onEvent(SDL_Event* event);

private:
    void init();
    void shutdown();
private:
    static Application* s_instance;
    ApplicationSpecification m_Specs;
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    float m_Timstep;
};