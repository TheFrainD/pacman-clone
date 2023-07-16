#pragma once

#include <SFML/Graphics.hpp>

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

    void Render(sf::RenderWindow *window) noexcept;
};
}  // namespace core