#include <iostream>
#include "femutils/copy.hpp"
#include "femerror/ErrorManager.hpp"
#include "femutils/create.hpp"
#include "femutils/delete.hpp"
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/thread.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;


int main_utils_interface(po::variables_map options_map,
                        po::options_description main_desc,
                        std::vector<std::string> src_vector,
                        std::vector<std::string> target_vector
                      )
  {
    boost::thread error_thread(ErrorManager, options_map, main_desc, src_vector, target_vector);
    if (options_map.count("help"))
    {
      std::cout<<main_desc<<std::endl;
      return 0;
    }










  }
