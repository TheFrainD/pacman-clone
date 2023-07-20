#include "core/game.h"

#include <SFML/Window/Event.hpp>

#include "core/factory.h"
#include "system/player.h"
#include "system/renderer.h"

namespace core {
Game::Game() : window_ {sf::VideoMode {800, 600}, "Pacman"} {
    window_.setVerticalSyncEnabled(true);

    const auto player {factory::CreatePlayer(registry_, cache_manager_)};
}

Game::~Game() {}

void Game::Run() noexcept {
    while (window_.isOpen()) {
        const float dt {dt_clock_.restart().asSeconds()};

        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
        }

        sys::player::InputUpdate(registry_, dt);

        window_.clear(sf::Color::Black);

        sys::renderer::RenderSprites(registry_, window_);

        window_.display();
    }
}
}  // namespace core