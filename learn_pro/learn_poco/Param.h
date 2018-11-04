#pragma once
#include <string>
#include <utility>

struct Option
{
    std::pair<bool, int> m_httpPort = std::make_pair(false, 0);
};
