#include "lib_mbtiles.hh"
#include "sqlite3.h"


int mbtiles_t::get_tables(const std::string &file_name, std::vector<std::string> &tables)
{
  sqlite3 *db = 0;
  sqlite3_stmt *stmt = 0;

  if (sqlite3_open_v2(file_name.c_str(), &db, SQLITE_OPEN_READWRITE, NULL) != SQLITE_OK)
  {
    sqlite3_errmsg(db);
    sqlite3_close(db);
    return SQLITE_ERROR;
  }

  if (sqlite3_prepare_v2(db, "SELECT name FROM sqlite_master WHERE type='table'", -1, &stmt, 0) != SQLITE_OK)
  {
    sqlite3_errmsg(db);
    sqlite3_close(db);
    return SQLITE_ERROR;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    std::string table = (const char*)sqlite3_column_text(stmt, 0);
    tables.push_back(table);
  }

  sqlite3_finalize(stmt);
  sqlite3_close_v2(db);
  return SQLITE_OK;
}