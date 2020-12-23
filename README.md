zoo
===

zoo is a basic implementation of a plugin architecture in C++. I had
originally created this for a segment of my dissertation work that I
later dropped for being out of scope. Regardless, it was a valuable
exercise in understanding loading and using symbols and creating generic
APIs.

*Logo from [photo by Waldemar Brandt from
Pexels](https://www.pexels.com/@wb2008?utm_content=attributionCopyText&utm_medium=referral&utm_source=pexels)*

zoo overview
------------

Plugins must comply with a basic API:

-   A plugin called `name` must expose `createName` and `destroyName`
-   `createName` must return a pointer to a `new`'d `Name` held by the
    plugin
    -   Using a `shared_ptr` instead would be more C++
-   `destroyName` must destroy an existing `Name` object
-   `Name` objects must implement `makeSound` -- they are zoo animals
    after all

Plugins may be added to the designated plugins directory at any time,
even while `zoo` is running. If added, plugins will be picked up and
started on the fly.

building zoo
------------

zoo uses the typical CMake build process. I have only tested it with GCC
5.4 and Clang 11.0, but it should work with any modern C++ compiler.

``` {.bash}
mkdir build
cd build
cmake ..
make
./zoo
```

zoo directory layout
--------------------

Below is an example directory layout describing how each directory is
designed to be used in the plugin architecture.

    ├── build
    │   └── plugins               directory for installed plugins
    ├── CMakeLists.txt
    ├── doc                       directory for documentation
    ├── ext_plugins               directory for external (user defined) plugins
    │   ├── cow.o
    │   ├── plugins
    │   │   ├── libcow.so
    │   │   └── libzebra.so
    │   ├── README                build instructions for external plugins
    │   ├── src                   user-defined plugin sources
    │   │   ├── cow.cpp
    │   │   ├── cow.h
    │   │   ├── zebra.cpp
    │   │   └── zebra.h
    │   └── zebra.o
    ├── include                   main include directory
    │   └── animal.h              base abstract plugin class definition
    ├── plugins                   derived plugin class sources shipped with repo
    │   ├── cat.cpp
    │   ├── cat.h
    │   ├── CMakeLists.txt        builds .so files for each derived plugin
    │   ├── dog.cpp
    │   ├── dog.h
    │   ├── tiger.cpp
    │   └── tiger.h
    ├── README                    this file
    └── src                       main repo source
        ├── util                  utilities
        │   ├── globothy.cpp      glob files, used to find .so files
        │   ├── globothy.h
        │   ├── libnameothy.cpp   extract lib name from .so files
        │   └── libnameothy.h
        └── zoo.cpp               main(), runs two threads to find/call plugins
