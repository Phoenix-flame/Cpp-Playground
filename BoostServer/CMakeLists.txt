cmake_minimum_required(VERSION 3.16)
project (TestLua)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread ")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TestLua_SOURCE_DIR}/cmake")
set(APP_TARGET TestLua)

file(GLOB core_src
    "src/*.cpp"
)

add_executable(${APP_TARGET}
	main.cpp
    ${core_src}
)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(
    ${APP_TARGET}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

find_package(Boost 1.40.0 REQUIRED system)

target_compile_features(${APP_TARGET}
    PRIVATE
    cxx_std_17
)


target_link_libraries(${APP_TARGET} ${Boost_LIBRARIES})
