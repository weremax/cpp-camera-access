## Vision
```
g++ main.cpp -o vision_test $(pkg-config --cflags opencv4) $(pkg-config --libs opencv4)
```
However, on arch linux I needed to create the following: CMakeLists.txt
 - File name too long error after fixing the library issues.
```
cmake_minimum_required(VERSION 3.10)
project(OpenCVExample)
find_package(OpenCV REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
```
Run the following:
```
mkdir build && cd build && cmake .. && make
```
