#include "GameEngine.h"
#include <memory>

int main()
{
    auto myGame = std::make_unique<GameEngine>();
    myGame->run();
    return 0;
}
