#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <entt/entity/fwd.hpp>

namespace sys::player {

void InputUpdate(entt::registry &registry, float dt) noexcept;

}