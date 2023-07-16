#include "core/game.h"

namespace core {
Game::Game()
    : window_ {sf::VideoMode {800, 600}, "Pacman"},
      render_thread_ {[this](auto *window) { this->Render(window); }, &window_} {
    window_.setActive(false);
    render_thread_.launch();
}

Game::~Game() {}

void Game::Run() noexcept {
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
        }
    }
}

void Game::Render(sf::RenderWindow *window) noexcept {
    window->setActive(true);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));

    while (window->isOpen()) {
        window->clear(sf::Color::Black);
        window->draw(shape);
        window->display();
    }
}
}  // namespace core