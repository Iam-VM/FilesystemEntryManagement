#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;

 int main_utils_interface(po::variables_map options_map, po::options_description main_desc)
 {
   if (options_map.count("help"))
   {
     std::cout<<main_desc<<std::endl;
     return 0;
   }
   
 }
