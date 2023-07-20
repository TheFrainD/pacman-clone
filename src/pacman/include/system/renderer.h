#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <entt/entity/fwd.hpp>

namespace sys::renderer {

void RenderSprites(entt::registry &registry, sf::RenderWindow &window) noexcept;

}