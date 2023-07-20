#include "core/factory.h"

#include <SFML/Graphics/Texture.hpp>

#include "component/player_controller.h"
#include "component/sprite_renderer.h"
#include "component/transform.h"

using namespace entt::literals;

namespace core::factory {

entt::entity CreatePlayer(entt::registry &registry, core::res::CacheManager &cache_manager) noexcept {
    entt::entity e = registry.create();

    registry.emplace<comp::Transform>(e, sf::Vector2f {30.0F, 40.0F});

    auto texture_res {cache_manager.AddResource<sf::Texture>("frog_texture"_hs)};
    auto texture {texture_res.first->second};
    texture->loadFromFile("data/sprites/frog.png");

    auto sprite_res {cache_manager.AddResource<sf::Sprite>("frog_sprite"_hs, *texture)};

    registry.emplace<comp::SpriteRenderer>(e, sprite_res.first->second, sf::IntRect(0, 0, 11, 1));

    registry.emplace<comp::PlayerController>(e, 100.0F);

    return e;
}

}  // namespace core::factory