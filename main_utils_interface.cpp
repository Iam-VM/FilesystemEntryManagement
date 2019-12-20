#include <iostream>
#include "femutils/copy.hpp"
#include "femutils/create.hpp"
#include "femutils/delete.hpp"
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;
bool flag_state = false;


 int main_utils_interface(po::variables_map options_map,
                          po::options_description main_desc,
                          std::vector<std::string> src_vector,
                          std::vector<std::string> target_vector
                        )

 {

   if (options_map.count("help"))
   {
     std::cout<<main_desc<<std::endl;
     return 0;
   }
   for (auto& iter : options_map)
   {
     if (iter.first() == "copy")
     {
       flag_state = true;

     }
     if (iter.first() == "create" && )
     {
       flag_state = true;

     }
     if (iter.first() == "copy")
     {
       flag_state = true;

     }

   }



 }
