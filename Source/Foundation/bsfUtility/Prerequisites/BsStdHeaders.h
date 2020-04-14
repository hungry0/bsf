#pragma once

#include <cmath>
#include <limits>

#include <assert.h>
#include <utility>
#include <vector>
#include <array>


namespace bs
{
    // TODO 加自定义内存分配器
    template<typename T>
    using Vector = std::vector<T>;
}