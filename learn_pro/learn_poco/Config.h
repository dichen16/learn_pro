#pragma once
#include "Param.h"

class Config
{
public:
    static Config& instance();
    Option m_option;
};
