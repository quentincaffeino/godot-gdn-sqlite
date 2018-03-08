
#include "GDSQLite.h"
#include <sqlite3.h>
#include <OS.hpp>


int GDSQLite::open(const String filename)
{
  String path = OS::get_user_data_dir() + String("/") + filename;

  db = sqlite3pp::database(path.alloc_c_string());

  return db.error_code();
}


// int GDSQLite::command(const String query)
// {
//   sqlite3pp::command cmd(
//     db,
//     query.alloc_c_string()
//   );

//   return db.error_code();
// }


int GDSQLite::query(const String query)
{
  sqlite3pp::query qry(
    db,
    query.alloc_c_string()
  );

  return db.error_code();
}


Array GDSQLite::select(const String query)
{
  Array result;

  sqlite3pp::query qry(
    db,
    query.alloc_c_string()
  );

  for (sqlite3pp::query::iterator i = qry.begin(); i != qry.end(); ++i)
  {
    Dictionary d;

    for (int j = 0; j < qry.column_count(); ++j)
    {
      d[qry.column_name(j)] = (*i).get<char const*>(j);
    }

    result.append(d);
  }

  return result;
}
