cmake_minimum_required(VERSION 3.0.0)
project(SugoiDict VERSION 0.1.0)

include(CTest)
enable_testing()

set(SRC ${CMAKE_SOURCE_DIR}/src/)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(SugoiDict ${SRC}/main.cpp ${SRC}/database.cpp)

target_link_libraries(SugoiDict jsoncpp)

target_link_libraries(SugoiDict sqlite3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
