This folder emulates someone else writing plugins. They should be compiled and
then copied over to build/plugins.

This is to test if the update thread can capture new plugins, and if the
zookeeper thread can run the functions within them

The included CMakeLists.txt should take care of this for you.

```bash
mkdir build
cd build
cmake ..
make
make install
```

If `zoo` is running, you should see it pick up two new plugins after running
`make install`.
