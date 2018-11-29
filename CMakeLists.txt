cmake_minimum_required(VERSION 2.8)
project(ModellingAssignment2)

set(CMAKE_CXX_STANDARD 14)
include_directories(includes)
add_executable(ModellingAssignment2 src/main.cpp includes/Matrix.h src/Matrix.cpp src/AMatrix.cpp includes/AMatrix.h src/Component.cpp includes/Component.h src/Resistance.cpp includes/Resistance.h src/Capacitance.cpp includes/Capacitance.h src/Inductance.cpp includes/Inductance.h src/VoltageSource.cpp includes/VoltageSource.h src/CurrentSource.cpp
        includes/CurrentSource.h src/ZMatrix.cpp includes/ZMatrix.h src/XMatrix.cpp includes/XMatrix.h includes/matplotlibcpp.h)
find_package(PythonLibs 2.7 REQUIRED)
target_include_directories(ModellingAssignment2 PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(ModellingAssignment2 ${PYTHON_LIBRARIES})
