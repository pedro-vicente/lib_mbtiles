#ifndef LIB_MBTILES_HH_
#define LIB_MBTILES_HH_

#include <string>

class mbtiles_t
{
public:
  mbtiles_t() {}
  int read(const std::string &file_name);

};

#endif