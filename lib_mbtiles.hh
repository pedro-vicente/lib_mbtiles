#ifndef LIB_MBTILES_HH_
#define LIB_MBTILES_HH_

#include <string>
#include <vector>
#include <iostream>

class mbtiles_t
{
public:
  mbtiles_t() {}
  int read(const std::string &file_name);
  int get_tables(const std::string &file_name, std::vector<std::string> &tables);

};

#endif