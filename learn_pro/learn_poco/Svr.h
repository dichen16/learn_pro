#pragma once
#include "Poco/Util/ServerApplication.h"

using Poco::Util::ServerApplication;

class Svr : public ServerApplication
{
protected:
    int main(const std::vector<std::string>& args);
};