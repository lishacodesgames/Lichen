#include <Lichen.h>

class Sandbox : public Lichen::Application {
public:
   Sandbox() = default;
   ~Sandbox() = default;
};

Lichen::Application* Lichen::CreateApplication() { return new Sandbox(); }