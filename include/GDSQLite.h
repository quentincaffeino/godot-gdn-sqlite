
#ifndef GDSQLITE_H
#define GDSQLITE_H

#include <sqlite3pp.h>

#include <core/Godot.hpp>
#include <Reference.hpp>
#include "Array.hpp"


using namespace godot;


class GDSQLite : public GodotScript<Reference>
{ 
  GODOT_CLASS(GDSQLite)

public:
  int open(const String filename);

  // int command(const String query);

  int query(const String query);

  Array select(const String query);


private:
  sqlite3pp::database db;
  // sqlite3pp::command cmd;


public:
  static void _register_methods()
  {
    register_method("open", &GDSQLite::open);
    register_method("query", &GDSQLite::query);
    register_method("select", &GDSQLite::select);
  }

  ~GDSQLite()
  {
    db.disconnect();
  }
};

#endif
