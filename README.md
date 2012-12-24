This C++ project implements a random number generator which outputs a unique 32-bit integer each time it's called, and verifies that the first 2<sup>32</sup> integers returns really are unique.

[CMake](http://www.cmake.org/) is required to build.

To run the test on Windows:

* Open a command prompt and navigate to the folder containing `CMakeLists.txt`.
* `mkdir build`
* `cd build`
* `cmake ..` (You can optionally specify a toolchain using CMake's `-G` argument.)
* `cmake --build . --config Release`
* `ctest .`
