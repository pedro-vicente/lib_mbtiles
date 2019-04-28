#include "lib_mbtiles.hh"

int main(int argc, const char* argv[])
{
  mbtiles_t mb;
  std::vector<std::string> tables;
  if (mb.get_tables(argv[1], tables) < 0)
  {

  }

  //Metadata
  //The database MUST contain a table or view named `metadata`.
  //This table or view MUST yield exactly two columns of type `text`, named `name` and
  //`value`. A typical create statement for the `metadata` table:
  //CREATE TABLE metadata(name text, value text);

  //Tiles
  //The database MUST contain a table named `tiles`.
  //The table MUST contain three columns of type `integer`, named `zoom_level`, `tile_column`,
  //`tile_row`, and one of type `blob`, named `tile_data`.
  //A typical `create` statement for the `tiles` table:
  //CREATE TABLE tiles(zoom_level integer, tile_column integer, tile_row integer, tile_data blob);

  for (size_t idx = 0; idx < tables.size(); idx++)
  {
    std::cout << tables.at(idx) << "\n";
  }
  return 0;
}