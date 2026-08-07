#include <lchpch.h>
#include <Lichen.h>
#include "EntryPoint.h"

class Sandbox : public lichen::Application {
public:
   Sandbox() = default;
   ~Sandbox() = default;
};

std::unique_ptr<lichen::Application> lichen::CreateApplication() { return std::make_unique<Sandbox>(); }
