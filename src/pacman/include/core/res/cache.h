#pragma once

#include <entt/resource/cache.hpp>

#include "core/res/loader.h"

namespace core::res {
template <typename T>
using Cache = entt::resource_cache<T, Loader<T>>;
}