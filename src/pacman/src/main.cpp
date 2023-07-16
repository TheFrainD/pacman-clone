#include <memory>

#include "core/game.h"

int main(int argc, char *argv[]) {
    auto game = std::make_unique<core::Game>();
    game->Run();
    return 0;
}