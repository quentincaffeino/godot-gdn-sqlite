
# GDNative SQLite wrapper for Godot 3


## Installation

```sh
$ mkdir lib &&
  cd lib
```

You need to download SQLite source code and place it under `lib/sqlite` or just use this command:
```sh
$ wget https://sqlite.org/2018/sqlite-amalgamation-3220000.zip &&
  unzip sqlite-amalgamation-3220000.zip &&
  rm sqlite-amalgamation-3220000.zip &&
  mv sqlite-amalgamation-3220000 sqlite
```

Next step is to get SQLiteCpp wrapper:
```sh
$ git clone https://github.com/SRombauts/SQLiteCpp.git
```

Last step is to compile module using:
```sh
$ make
```
