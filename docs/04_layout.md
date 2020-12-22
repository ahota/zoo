## zoo directory layout

Below is an example directory layout describing how each directory is designed
to be used in the plugin architecture.

```
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
```
