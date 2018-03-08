
Import('env target_platform target_arch host_platform')

# SQLite
env.Append(CPPPATH = [ '../SQLite/include' ])
env.Append(LIBS = [ 'SQLite.' + target_platform + '.' + target_arch ])
env.Append(LIBPATH = [ '../SQLite/bin' ])

# SQLite wrapper
env.Append(CPPPATH = [ 'lib/sqlite3pp/headeronly_src' ])
