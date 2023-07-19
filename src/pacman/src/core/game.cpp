#include "core/game.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "component/sprite_renderer.h"
#include "component/transform.h"
#include "core/factory.h"
#include "system/renderer.h"

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

    entt::entity e = registry_.create();

    registry_.emplace<comp::Transform>(e, sf::Vector2f {30.0f, 40.0f});

    sf::Texture texture;
    texture.loadFromFile("data/sprites/frog.png");
    registry_.emplace<comp::SpriteRenderer>(e, sf::Sprite(texture));

    while (window->isOpen()) {
        window->clear(sf::Color::Black);

        sys::renderer::RenderSprites(registry_, window);

        window->display();
    }
}
}  // namespace core