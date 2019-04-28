#ifndef LIB_MBTILES_HH_
#define LIB_MBTILES_HH_

#include <string>
#include <vector>
#include <iostream>
#include "sqlite3.h"

class mbtiles_t
{
public:
  mbtiles_t() :
    m_db(0)
  {}
  ~mbtiles_t()
  {
    sqlite3_close(m_db);
  }
  int get_tables(const std::string &file_name, std::vector<std::string> &tables);
  int get_metadata();
  int get_tiles(size_t zoom_level, size_t  tile_column , size_t tile_row);

private:
  sqlite3 *m_db;

};

#endif