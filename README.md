# qtm-calc-shared

qtm-calc-shared is a shared version of [qtm-calc](https://github.com/andinoriel/qtm-calc) intended for use via CMake.

## Build

1. First of all make sure you have the Boost library installed on your system (see more [Boost installation on Windows](https://www.boost.org/doc/libs/1_75_0/more/getting_started/windows.html) or [Boost installation on *nix](https://www.boost.org/doc/libs/1_75_0/more/getting_started/unix-variants.html));

2. Clone this project and then cd to the project folder;

3. Configure the project using CMake:
```
$ cmake -B ./build -G <preferred generator> -DCMAKE_BUILD_TYPE=<Debug|Release>
```

4. Then run build command:
```
$ cmake --build ./build --config <Debug|Release>
```

5. You've done! The builded binary file available in the build directory.

## Usage

In your CMakelists.txt:
```cmake
cmake_minimum_required(VERSION 3.12)

project(project_name LANGUAGES CXX)

add_subdirectory(/path/to/qtm-calc/dir EXCLUDE_FROM_ALL)
add_executable(executable_name main.cpp)
target_link_libraries(executable_name PRIVATE libqtmcalc)
```

In your sources:
```cpp
#include <qtm-calc/core.hpp>
#include <qtm-calc/data.hpp>

// somewhere in code
qtm::qtm x(10, 1, 1.5, 0.7, 0, -1);
if (x.is_fs_outdated()) {
  x.calc_final_states();
}
std::cout << x.final_states();

// ...
```

## License

This project is licensed under the [MIT License](LICENSE).

## Dependents

This project is used by [gw-dss-cpp](https://github.com/Vemestael/gw-dss-cpp/) - predict tool based on queuing theory.

## Credits

My thanks to the developers of the [Boost C++ Libraries](https://www.boost.org/) and [pybind11](https://github.com/pybind/pybind11).

Especial thanks to [IceArrow256](https://github.com/IceArrow256) and [Vemestael](https://github.com/Vemestael) for help in writing computing algorithms and code structuring.
