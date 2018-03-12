
#include "GDNSQLite.h"
#include <OS.hpp>


int GDNSQLite::open(const String filename)
{
  String path = OS::get_user_data_dir() + String("/") + filename;

  try {
    pDb.reset(new Database(path.alloc_c_string(), OPEN_READWRITE|OPEN_CREATE));

    return SQLITE_OK;
  } catch (std::exception& e) {
    printf("GDNSQLite: %s", e.what());
  }

  return SQLITE_ERROR;
}


Variant GDNSQLite::execute(const String sQuery, const Array aParameters)
{
  try {
    Statement query(*pDb.get(), sQuery.alloc_c_string());

    size_t i;
    // Bind parameters
    for (i = 0; i < aParameters.size(); ++i)
    {
      switch (aParameters[i].get_type())
      {
        case Variant::NIL:
          query.bind(i + 1);
          break;

        case Variant::BOOL:
          query.bind(i + 1, (bool)aParameters[i]);
          break;

        case Variant::INT:
          query.bind(i + 1, (int)aParameters[i]);
          break;

        case Variant::REAL:
          query.bind(i + 1, (double)aParameters[i]);
          break;

        case Variant::STRING:
          query.bind(i + 1, String((wchar_t)aParameters[i]).alloc_c_string());
          break;
      }
    }

    // Execute
    int sSelectStatementSize = sizeof(char) * 6 + 1;
    char sSelectQuery[sSelectStatementSize];
    strcpy(sSelectQuery, "SELECT");
    char sCheckStatement[sSelectStatementSize];
    memset(sCheckStatement, '\0', sizeof(sCheckStatement));
    strncpy(sCheckStatement, sQuery.alloc_c_string(), sSelectStatementSize - 1);

    // If executed SELECT statement fetch result
    if (strcmp(sSelectQuery, sCheckStatement) == 0) {
      Array result;

      while (query.executeStep())
      {
        Dictionary row;

        for (i = 0; i < query.getColumnCount(); ++i)
        {
          switch (query.getColumn(i).getType())
          {
            case SQLITE_INTEGER:
              row[query.getColumn(i).getName()] = query.getColumn(i).getInt();
              break;

            case SQLITE_FLOAT:
              row[query.getColumn(i).getName()] = query.getColumn(i).getDouble();
              break;

            case SQLITE_TEXT:
            case SQLITE_BLOB:
              row[query.getColumn(i).getName()] = query.getColumn(i).getString().c_str();
              break;

            case SQLITE_NULL:
              row[query.getColumn(i).getName()] = Variant();
              break;
          }
        }

        result.append(row);
      }

      return result;
    } else {
      // Else execute statement and return number of row modified.
      return query.exec();
    }
  } catch (std::exception& e) {
    printf("GDNSQLite: %s", e.what());
  }

  return Variant(); // Null
}


Variant GDNSQLite::executeRaw(const String sQuery)
{
  return execute(sQuery, Array());
}
