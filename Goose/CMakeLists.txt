cmake_minimum_required(VERSION 3.16)
project (Goose)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -L/usr/local/lib -liec61850 ")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Goose_SOURCE_DIR}/cmake")
set(APP_TARGET Goose)

include_directories(
  ./include
)

set(src
   main.cpp
   ./source/Publisher.cpp
)

find_library(iec61850
    NAMES libiec61850 iec61850
    HINTS "/usr/local/lib/"
)


message(hello ${iec61850})

add_executable(${APP_TARGET}
  ${src}
)

target_link_libraries(${APP_TARGET}
${iec61850}
)


