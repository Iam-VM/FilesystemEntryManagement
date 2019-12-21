#ifndef ERROR_MANAGER_HPP
#define ERROR_MANAGER_HPP

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;



int ErrorManager(po::variables_map options_map,
                        po::options_description main_desc,
                        std::vector<std::string> src_vector,
                        std::vector<std::string> target_vector
                      )
{
  if (!options_map.count("src"))
  {
    std::cout<<"\nFemErrorManager: --src <args>/-s <args> missing [code: -2]"<<std::endl;
    return -2;
  }
  else if (src_vector.size() == 0)
  {
    std::cout<<"\nFemErrorManager: --src used without <args> [code: -3]"<<std::endl;
    return -3;
  }

  if (!((options_map.count("copy") && options_map.count("target"))
     || (options_map.count("create"))
     || (options_map.count("delete"))
     || (options_map.count("dp"))
     || (options_map.count("details"))
     || (options_map.count("ls"))
     || (options_map.count("lsR"))
     || (options_map.count("move")  && options_map.count("target"))
     || (options_map.count("rename"))))
  {
    std::cout<<"\nFemErrorManager: Invalid options combination [code: -4]"<<std::endl;
    return -4;
  }

  if (!options_map.count("target") && src_vector.size() == 0)
  {
    std::cout<<"\nFemErrorManager: --target used without <args> [code: -5]"<<std::endl;
    return -5;
  }
  
  return 0;
}






#endif
