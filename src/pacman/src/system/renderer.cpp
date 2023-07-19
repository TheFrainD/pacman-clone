#include "system/renderer.h"

#include <entt/entity/registry.hpp>

#include "component/sprite_renderer.h"
#include "component/transform.h"

namespace sys::renderer {

void RenderSprites(entt::registry &registry, sf::RenderWindow *window) noexcept {
    const auto view = registry.view<comp::Transform, comp::SpriteRenderer>();

    view.each([&](auto &transform, auto &sprite_renderer) {
        sprite_renderer.sprite->setPosition(transform.position);
        window->draw(*sprite_renderer.sprite);
    });
}

}  // namespace sys::renderer