#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/StreamCopier.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Dynamic/Var.h"


class Handler : public Poco::Net::HTTPRequestHandler
{
public:
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
    {
        std::ostringstream oss;
        Poco::StreamCopier::copyStream(request.stream(), oss);
        std::string strRequest = oss.str();
        std::cout << strRequest << std::endl;
        
    }
    void ParseJson(Poco::JSON::Object::Ptr & jObject, std::string &output)
    {
        std::ostringstream oss;
        jObject->stringify(oss);
        output = oss.str();
    }
};