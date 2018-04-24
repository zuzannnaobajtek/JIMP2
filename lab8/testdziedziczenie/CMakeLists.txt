
project(testdziedziczenie)

set(HEDEAR_FILES TestDziedziczenie.h)
set(SOURCE_FILES TestDziedziczenie.cpp)

add_library(libtestdziedziczenie STATIC ${SOURCE_FILES})
target_include_directories(libtestdziedziczenie PUBLIC .)

add_executable(testdziedziczenie ${SOURCE_FILES} main.cpp)

target_link_libraries(testdziedziczenie libtestdziedziczenie)