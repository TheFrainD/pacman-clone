#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Thread.hpp>
#include <entt/entity/registry.hpp>

#include "core/res/cache_manager.h"

namespace core {
class Game {
public:
    Game();
    ~Game();

    Game(const Game &) = delete;
    Game(Game &&)      = delete;

    Game &operator=(const Game &) = delete;
    Game &operator=(Game &&)      = delete;

    void Run() noexcept;

private:
    sf::RenderWindow window_;
    sf::Thread render_thread_;
    entt::registry registry_;
    res::CacheManager cache_manager_;

    void Render(sf::RenderWindow *window) noexcept;
};
}  // namespace core