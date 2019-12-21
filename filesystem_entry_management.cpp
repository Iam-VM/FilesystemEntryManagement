#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <main_utils_interface.cpp>


namespace fs = boost::filesystem;
namespace po = boost::program_options;
namespace po_cmd_style = boost::program_options::command_line_style;
std::vector<std:string> src_vector;
std::vector<std::string> target_vector;



int main(int argc, char* argv[])
{

  po::options_description main_desc("Usage ");
  main_desc.add_options()
    ("copy,c", "to copy entries specified using --src or -s to entries specified using --target or -t")
    ("create,C", "to create entries specified using --src or -s")
    ("delete,d", "to move entries specified using --src or -s to Trash [if Trash exists. if not, will be permanently deleted!!]")
    ("dp", "for permanent deletion of entries specified using --src or -s")
    ("details,D", "to print details of entries specified using --src or -s")
    ("help,h", "for a breif usage description")
    ("ls", "to list entries in the entries specified using --src or -s")
    ("lsR", "to recursively list all entries in the entry specified using --src or -s")
    ("move, m", "to move entries specified using --src or -s to entries specified using --target or -t ")
    ("rename,r", po::value<std::string>(&new_name), "to rename entries specified using --src or -s [takes the new name as argument!!]")
    ("src, s", po::value<std::vector<std::string>>(&src_vector)->multitoken(), "to specify paths of source entries[entries can be files/directories/symlinks !!]")
    ("target, t", po::value<std::vector<std::string>>(&target_vector)->multitoken(), "to specify paths of the targets");

  int cmd_style = po_cmd_style::short_allow_next
                  | po_cmd_style::unix_style
                  | po_cmd_style::long_allow_next
                  | po_cmd_style::allows_slash_for_short
                  | po_cmd_style::allows_slash_for_long;
  try
  {
    po::variables_map options_map;
    auto cmd_parser = po::command_line_parser(argc, argv)
    .options(main_desc)
    .style(cmd_style)
    .allow_unregistered()
    .run();
    po::store(cmd_parser, options_map);
    po::notify(options_map);
  }
  catch(boost::system::error_code ec)
  {
    std::cerr<<main_desc<<std::endl;
    return -1;
  }

  int return_code = main_utils_interface(options_map, main_desc, src_vector, target_vector);


  return 0;
}
