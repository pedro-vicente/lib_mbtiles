#include "lib_mbtiles.hh"

int main(int argc, const char* argv[])
{
  mbtiles_t mb;
  if (mb.read(argv[1]) < 0)
  {

  }
  return 0;
}