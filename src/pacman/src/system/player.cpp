#include "system/player.h"

#include <SFML/System/Vector2.hpp>
#include <entt/entity/registry.hpp>

#include "component/player_controller.h"
#include "component/transform.h"

namespace {
sf::Vector2i GetDirection() noexcept {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        return {0, -1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        return {0, 1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        return {1, 0};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        return {-1, 0};
    }

    return {0, 0};
}
}  // namespace

namespace sys::player {

void InputUpdate(entt::registry &registry, float dt) noexcept {
    const auto direction = GetDirection();

    const auto view {registry.view<comp::Transform, comp::PlayerController>()};
    view.each([&](auto &transform, auto &player_controller) {
        const auto translation {static_cast<sf::Vector2f>(direction) * player_controller.speed * dt};
        transform.position += translation;
    });
}

}  // namespace sys::player