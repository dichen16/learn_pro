#include "Config.h"
#include "Poco/SingletonHolder.h"

namespace
{
    static Poco::SingletonHolder<Config> sh;
}

Config& Config::instance()
{
    return *sh.get();
}