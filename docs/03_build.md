## building zoo

zoo uses the typical CMake build process. I have only tested it with GCC 5.4
and Clang 11.0, but it should work with any modern C++ compiler.

```bash
mkdir build
cd build
cmake ..
make
./zoo
```
