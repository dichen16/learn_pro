#include "Svr.h"
#include "Factory.h"
#include "Poco/Net/HTTPServer.h"
#include "Config.h"

int Svr::main(const std::vector<std::string>& args)
{
    Factory::Ptr pFactory = new Factory();
    Poco::SharedPtr<Poco::Net::HTTPServer> pHttpSvr;
    Poco::Net::HTTPServerParams::Ptr pParams = new Poco::Net::HTTPServerParams();
    pParams->setMaxQueued(100);
    pParams->setMaxThreads(10);
    pParams->setKeepAlive(false);
    Poco::Net::ServerSocket svs(Poco::Net::SocketAddress(Config::instance().m_option.m_httpPort.second));
    //set-up a HTTPServer instance
    pHttpSvr = new Poco::Net::HTTPServer(pFactory, svs, pParams);
    //start the HTTPServer
    pHttpSvr->start();
    while (true)
    {
    }
    return 0;
}
