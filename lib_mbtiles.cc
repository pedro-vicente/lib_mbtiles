#include "lib_mbtiles.hh"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//mbtiles_t::get_tables
/////////////////////////////////////////////////////////////////////////////////////////////////////

int mbtiles_t::get_tables(const std::string &file_name, std::vector<std::string> &tables)
{
  sqlite3_stmt *stmt = 0;

  if (sqlite3_open_v2(file_name.c_str(), &m_db, SQLITE_OPEN_READWRITE, NULL) != SQLITE_OK)
  {
    sqlite3_errmsg(m_db);
    sqlite3_close(m_db);
    return SQLITE_ERROR;
  }

  if (sqlite3_prepare_v2(m_db, "SELECT name FROM sqlite_master WHERE type='table';", -1, &stmt, 0) != SQLITE_OK)
  {
    sqlite3_errmsg(m_db);
    sqlite3_close(m_db);
    return SQLITE_ERROR;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    std::string table = (const char*)sqlite3_column_text(stmt, 0);
    tables.push_back(table);
  }

  sqlite3_finalize(stmt);
  return SQLITE_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//mbtiles_t::get_metadata
/////////////////////////////////////////////////////////////////////////////////////////////////////

int mbtiles_t::get_metadata()
{
  sqlite3_stmt *stmt = 0;

  if (sqlite3_prepare_v2(m_db, "SELECT * FROM metadata;", -1, &stmt, 0) != SQLITE_OK)
  {
    sqlite3_errmsg(m_db);
    sqlite3_close(m_db);
    return SQLITE_ERROR;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    std::string row_name = (const char*)sqlite3_column_text(stmt, 0); //field 'name '
    std::string row_value = (const char*)sqlite3_column_text(stmt, 1); //field 'value '
    std::cout << row_name << " | " << row_value << "\n";
  }

  sqlite3_finalize(stmt);
  return SQLITE_OK;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//mbtiles_t::get_tile
/////////////////////////////////////////////////////////////////////////////////////////////////////

int mbtiles_t::get_tiles(size_t zoom_level, size_t  tile_column, size_t tile_row)
{
  sqlite3_stmt *stmt = 0;
  std::string sql = "SELECT tile_data FROM tiles WHERE ";
  sql += "zoom_level=";
  sql += std::to_string(zoom_level);
  sql += " AND tile_column=";
  sql += std::to_string(tile_column);
  sql += " AND tile_row=";
  sql += std::to_string(tile_row);
  sql += ";";

  if (sqlite3_prepare_v2(m_db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK)
  {
    sqlite3_errmsg(m_db);
    sqlite3_close(m_db);
    return SQLITE_ERROR;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
  
  }

  sqlite3_finalize(stmt);
  return SQLITE_OK;
}