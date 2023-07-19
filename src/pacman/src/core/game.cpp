#include "core/game.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "core/factory.h"
#include "system/renderer.h"

namespace core {
Game::Game()
    : window_ {sf::VideoMode {800, 600}, "Pacman"},
      render_thread_ {[this](auto *window) { this->Render(window); }, &window_} {
    window_.setActive(false);
    render_thread_.launch();

    const auto player = factory::CreatePlayer(registry_, cache_manager_);
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

    while (window->isOpen()) {
        window->clear(sf::Color::Black);

        sys::renderer::RenderSprites(registry_, window);

        window->display();
    }
}
}  // namespace core