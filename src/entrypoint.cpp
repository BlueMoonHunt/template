#include "core/application.h"

int main() {
    Application* app = new Application(ApplicationSpecification{
       .name = "APP-NAME",
       .width = 900,
       .height = 500,
        });

    app->run();

    delete app;
}