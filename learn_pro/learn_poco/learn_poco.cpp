#include "Svr.h"
#include "Config.h"
#include "tclap/CmdLine.h"

void parseOptions(int argc, char** argv)
{
    Option &param = Config::instance().m_option;
    try
    {
        // Define the command line object.
        TCLAP::CmdLine cmd("Cloud command line option");

        // Define a value argument and add it to the command line.
        TCLAP::ValueArg<int> argPort("p", "port", "server http port", false, 9185, "integer", cmd);
        // Parse the args.
        cmd.parse(argc, argv);

        param.m_httpPort = std::make_pair(argPort.isSet(), argPort.getValue());

    }
    catch (TCLAP::ArgException &e)  // catch any exceptions
    {
        std::cout << "[command line] " << e.error() << std::endl;
        exit(-1);
    }
}

int main(int argc, char **argv)
{
    Svr app;
    parseOptions(argc, argv);
    return app.run(1, argv);
}