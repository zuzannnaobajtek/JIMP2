
project(rodzicdziecko)

set(HEDEAR_FILES RodzicDziecko.h)
set(SOURCE_FILES RodzicDziecko.cpp)

add_library(librodzicdziecko STATIC ${SOURCE_FILES})
target_include_directories(librodzicdziecko PUBLIC .)

add_executable(rodzicdziecko ${SOURCE_FILES} main.cpp)

target_link_libraries(rodzicdziecko librodzicdziecko)
