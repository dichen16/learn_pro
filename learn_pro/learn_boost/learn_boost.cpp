#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "boost/program_options.hpp"
#include <boost/algorithm/string/join.hpp>

namespace po = boost::program_options;
using namespace std;

int main(int argc, char** argv)
{
    // Declare the supported options.
    int opt;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("optimization", po::value<int>(&opt)->default_value(10),
            "optimization level")
            ("include-path,I", po::value< vector<string> >(),
                "include path")
                ("input-file", po::value< vector<string> >(), "input file")
        ;
    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
        options(desc).positional(p).run(), vm);
    po::notify(vm);


    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }
    if (vm.count("include-path"))
    {
        std::string result = boost::algorithm::join(vm["include-path"].as< vector<string> >(), " ");
        std::cout << "Include paths are: "
            << result << "\n";
    }

    if (vm.count("input-file"))
    {
        std::string result = boost::algorithm::join(vm["input-file"].as< vector<string> >(), " ");
        std::cout << "Input files are: "
            << result << "\n";
    }

    std::cout << "Optimization level is " << opt << "\n";
}// main 