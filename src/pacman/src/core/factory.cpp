#include "core/factory.h"

#include <SFML/Graphics/Texture.hpp>

#include "component/sprite_renderer.h"
#include "component/transform.h"

namespace core::factory {

entt::entity CreatePlayer(entt::registry &registry) noexcept {
    entt::entity e = registry.create();

    registry.emplace<comp::Transform>(e, sf::Vector2f {30.0f, 40.0f});

    sf::Texture texture;
    texture.loadFromFile("data/sprites/frog.png");
    registry.emplace<comp::SpriteRenderer>(e, sf::Sprite(texture));

    return e;
}

}  // namespace core::factory