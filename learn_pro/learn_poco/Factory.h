#pragma once
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/AutoPtr.h"
#include "Handler.h"

class Factory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    typedef Poco::SharedPtr<Factory> Ptr;
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request)
    {
        Poco::Net::HTTPRequestHandler* pHandler = nullptr;
        pHandler = new Handler;
        return pHandler;
    }
};