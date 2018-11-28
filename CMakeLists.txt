cmake_minimum_required(VERSION 3.12)
project(ModellingAssignment2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ModellingAssignment2 main.cpp Matrix.h Matrix.cpp AMatrix.cpp AMatrix.h Component.cpp Component.h Resistance.cpp Resistance.h Capacitance.cpp Capacitance.h Inductance.cpp Inductance.h VoltageSource.cpp VoltageSource.h CurrentSource.cpp CurrentSource.h ZMatrix.cpp ZMatrix.h)