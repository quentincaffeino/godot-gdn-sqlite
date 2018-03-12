
#ifndef GDNSQLITE_H
#define GDNSQLITE_H

#include <memory>

#include <core/Godot.hpp>
#include <Reference.hpp>
#include "Array.hpp"

#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>


using namespace SQLite;
using namespace godot;


class GDNSQLite : public GodotScript<Reference>
{ 
  GODOT_CLASS(GDNSQLite);

public:
  int open(const String filename);

  Variant execute(const String sQuery, const Array aParameters);

  Variant executeRaw(const String sQuery);

  static void _register_methods()
  {
    register_method("open", &GDNSQLite::open);
    register_method("execute", &GDNSQLite::execute);
    register_method("executeRaw", &GDNSQLite::executeRaw);
  }


private:
  std::shared_ptr<Database> pDb;

};

#endif
