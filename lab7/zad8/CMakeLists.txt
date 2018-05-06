
project(zad8)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Zad8.cpp)

add_library(libzad8 STATIC ${SOURCE_FILES})
target_include_directories(libzad8 PUBLIC .)

add_executable(zad8 ${SOURCE_FILES} main.cpp)

target_link_libraries(zad8 libzad8)
