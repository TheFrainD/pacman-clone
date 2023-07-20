#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdint>
#include <entt/resource/resource.hpp>

namespace comp {

class SpriteRenderer {
public:
    entt::resource<sf::Sprite> sprite;

    explicit SpriteRenderer(const entt::resource<sf::Sprite> &sprite);
    SpriteRenderer(const entt::resource<sf::Sprite> &sprite, const sf::IntRect &sprite_sheet_);

    void SetSheetTile(const sf::Vector2i &position) noexcept;

private:
    sf::IntRect sprite_sheet_;

    void UpdateRect() const noexcept;
};

}  // namespace comp