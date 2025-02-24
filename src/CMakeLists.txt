cmake_minimum_required(VERSION 3.16)

project(qsqlgen LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)
add_library(qsqlgen SHARED
    qsqlgen_global.h
  qsqlgen.cpp
  qsqlgen.h
  sqlitedb.h sqlitedb.cpp
  cond.h cond.cpp
  query.h query.cpp
  insert.h insert.cpp
  delete.h delete.cpp
  update.h update.cpp
  utils.h utils.cpp

)

target_link_libraries(qsqlgen PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(qsqlgen
    PRIVATE PRIVATE Qt6::Sql
)

target_compile_definitions(qsqlgen PRIVATE QSQLGEN_LIBRARY)
target_link_libraries(qsqlgen PRIVATE Qt6::Core5Compat)
