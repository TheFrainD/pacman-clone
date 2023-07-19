#pragma once

#include <entt/entity/registry.hpp>

#include "core/res/cache_manager.h"

namespace core::factory {

entt::entity CreatePlayer(entt::registry &registry, core::res::CacheManager &cache_manager) noexcept;

}