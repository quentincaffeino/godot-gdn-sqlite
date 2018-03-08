
import os


def add_source(sources, name):
  sources.append(name)

def add_sources(sources, dir, extension):
  for f in os.listdir(dir):
      if f.endswith('.' + extension):
          sources.append(dir + '/' + f)


Import('env target_platform target_arch host_platform sources')

env['STATIC_AND_SHARED_OBJECTS_ARE_THE_SAME']=1


# SQLite
add_sources(sources, 'lib/sqlite3', 'c')
env.Append(CPPPATH = [ 'lib/sqlite3' ])
env.Append(CCFLAGS = [ '-DSQLITE_OMIT_LOAD_EXTENSION', '-DSQLITE_CORE', '-O2' ])
env.Append(LIBS = [ 'pthread' ])


# SQLite wrapper
add_sources(sources, 'lib/sqlite3pp/src', 'cpp')
env.Append(CPPPATH = [ 'lib/sqlite3pp/src' ])
