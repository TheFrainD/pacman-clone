#pragma once

#include <entt/entity/registry.hpp>

namespace core::factory {

entt::entity CreatePlayer(entt::registry &registry) noexcept;

}