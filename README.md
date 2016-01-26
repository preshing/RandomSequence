This C++ project implements a random number generator which outputs a unique 32-bit integer each time it's called, and verifies that the first 2<sup>32</sup> integers returns really are unique. The algorithm is described in the blog post [How to Generate a Sequence of Unique Random Integers](http://preshing.com/20121224/how-to-generate-a-sequence-of-unique-random-integers).

[CMake](http://www.cmake.org/) is required to build.

To run the test on Windows:

* Open a command prompt and navigate to the folder containing `CMakeLists.txt`.
* `mkdir build`
* `cd build`
* `cmake ..` (You can optionally specify a toolchain using CMake's `-G` argument.)
* `cmake --build . --config Release`
* `ctest .`

## LICENSE

Released to the [public domain](http://unlicense.org).
