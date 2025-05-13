#pragma once

struct ApplicationSpecification {
    const char* name;
    int width = 0, height = 0;
};

class Application {
public:
    Application(const ApplicationSpecification& specs);
    ~Application();

    static inline Application* Get() { return s_instance; }

    void run();
    
    private:
    void init();
    void shutdown();
private:
    static Application* s_instance;
    ApplicationSpecification m_Specs;
    float m_Timstep;
};