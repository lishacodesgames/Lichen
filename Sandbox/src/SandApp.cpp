#include <Lichen.h>

class Sandbox : public lichen::Application {
public:
   Sandbox() = default;
   ~Sandbox() = default;
};

lichen::Application* lichen::CreateApplication() { return new Sandbox(); }