#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <entt/resource/resource.hpp>

namespace comp {

struct SpriteRenderer {
    entt::resource<sf::Sprite> sprite;
};

}  // namespace comp