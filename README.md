# Kancolle-Kanmutsu-Command-System-For-Linux
A fleet command system for Kancolle that runs on Linux. The system operates based on a fleet information plugin for the POI browser. It can read exported .csv files and plan EX map through the command line.

## Build

```bash
make            # produces build/main
./build/main    # or: cd build && ./main
```

The program looks for `KanmutsuListUTF8.csv` (UTF-8, the export from POI) next to the executable first, then in its parent directory, and exits with a message if neither exists.

Every fleet assignment change (assign / re-assign / cancel / reset on startup) is written back to that csv immediately: the whole file is first written to `<name>.csv.tmp`, checked column by column, then swapped in, leaving the previous version as `<name>.csv.bak`.

