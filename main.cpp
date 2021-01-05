#include <boost/program_options/options_description.hpp>
#include <boost/program_options/option.hpp>
#include <boost/any.hpp>
using namespace std;
#include <iostream>

#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <iostream>
#include "LineSegmentation.hpp"
int main(int argc, char** argv)
{
    if(argc<2)
    {
        printf("Too few arguments\n");
    }
    else
    {
        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
            ("output", po::value<std::string>()->default_value(""))
            ("filename", po::value<std::string>()->default_value(""));

        po::variables_map vm;
        po::store(po::parse_command_line(argc,argv,desc),vm);
        po::notify(vm);

        std::string output = boost::any_cast<std::string>(vm["output"].value());
        std::string input  = boost::any_cast<std::string>(vm["filename"].value());
        std::cout << "output: " << boost::any_cast<std::string>(vm["output"].value()) << "'\n";
        std::cout << "filename: '" << boost::any_cast<std::string>(vm["filename"].value()) << "'\n";

        LineSegmentation line_segmentation(input.c_str(),output.c_str());

        vector<cv::Mat> lines = line_segmentation.segment();
    }
}