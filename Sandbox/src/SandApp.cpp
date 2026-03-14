#include <Lichen.h>

class Sandbox : public Lichen::Application {
public:
   Sandbox() = default;
   ~Sandbox() = default;
};

int main() {
   Sandbox* myGame = new Sandbox();

   
   delete myGame;
   return 0;
}