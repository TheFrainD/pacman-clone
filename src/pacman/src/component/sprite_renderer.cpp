#include "component/sprite_renderer.h"

#include <SFML/Graphics/Texture.hpp>

namespace comp {

SpriteRenderer::SpriteRenderer(const entt::resource<sf::Sprite> &sprite)
    : sprite(sprite), sprite_sheet_({1, 1}, {0, 0}) {}

SpriteRenderer::SpriteRenderer(const entt::resource<sf::Sprite> &sprite, const sf::IntRect &sprite_sheet_)
    : sprite(sprite), sprite_sheet_(sprite_sheet_) {
    UpdateRect();
}

void SpriteRenderer::SetSheetTile(const sf::Vector2i &position) noexcept {
    sprite_sheet_.left   = position.x;
    sprite_sheet_.height = position.y;
    UpdateRect();
}

void SpriteRenderer::UpdateRect() const noexcept {
    sf::Vector2f texture_size {sprite->getTexture()->getSize()};

    sf::Vector2i tile_size {static_cast<std::int32_t>(texture_size.x / sprite_sheet_.width),
                            static_cast<std::int32_t>(texture_size.y / sprite_sheet_.height)};

    sf::IntRect texture_rect {{tile_size.x * sprite_sheet_.left, tile_size.y * sprite_sheet_.top}, tile_size};
    sprite->setTextureRect(texture_rect);
}
}  // namespace comp