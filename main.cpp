
#include "Exception.h"
#include "Application.h"

int main() {
    Application* application = new Application();
    application->init();
    application->start();
    delete application;
    return 0;
}
