cmake_minimum_required(VERSION 3.26)
project(protobuf_cpp_mukbo_writer C CXX)
# find_package(Protobuf CONFIG REQUIRED)

set(CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc")
set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")

set(CMAKE_SOURCE_DIR C:/Users/kamat/OneDrive/Documents/GitHub/LearningCPlusPlus/Practice/pcme)

set(PROTOBUF_INSTALL_DIR_ABSL "C:/Program Files (x86)/protobuf/lib/cmake/absl")
set(PROTOBUF_INSTALL_DIR_PROTOBUF "C:/Program Files (x86)/protobuf/lib/cmake/protobuf")
set(PROTOBUF_INSTALL_DIR_UTF8_RANGE "C:/Program Files (x86)/protobuf/lib/cmake/utf8_range")

# set(CMAKE_MODULE_PATH ${PROTOBUF_INSTALL_DIR_PROTOBUF})
# find_package(protobuf CONFIG REQUIRED)
# add_library(protobuf::gmock STATIC IMPORTED)
set(CMAKE_MODULE_PATH ${PROTOBUF_INSTALL_DIR_PROTOBUF})
find_package(protobuf CONFIG REQUIRED)
include(protobuf-config)
# include(protobuf-config-version)
include(protobuf-generate)
include(protobuf-module)
include(protobuf-options)
include(protobuf-targets)
include(protobuf-targets-noconfig)

set(CMAKE_MODULE_PATH ${PROTOBUF_INSTALL_DIR_ABSL})
find_package(absl REQUIRED)
include(abslConfig)
include(abslConfigVersion)
include(abslTargets)
include(abslTargets-noconfig)

set(CMAKE_MODULE_PATH ${PROTOBUF_INSTALL_DIR_UTF8_RANGE})
find_package(utf8_range REQUIRED)
include(utf8_range-config)
include(utf8_range-targets)
include(utf8_range-targets-noconfig)


add_executable(protobuf_cpp_mukbo_writer
            
                write_to_file.cpp
                ${CMAKE_SOURCE_DIR}/proto/addressbook.pb.h 
            ${CMAKE_SOURCE_DIR}/proto/addressbook.pb.cc
                )               
                               
set(PROTOBUF_INCLUDE_DIR "C:/Program Files (x86)/protobuf/include")
include_directories(${PROTOBUF_INCLUDE_DIR})

target_include_directories(protobuf_cpp_mukbo_writer PUBLIC ${PROTOBUF_INCLUDE_DIR})
# target_include_directories(protobuf_cpp_mukbo_writer PUBLIC ${PROTOBUF_INCLUDE_DIR}/dependencies/protobuf/third_party/abseil-cpp)

 target_link_libraries(protobuf_cpp_mukbo_writer
 protobuf) 
#                         ${CMAKE_SOURCE_DIR}/dependencies/protobuf/build/libprotobuf.a 
#                         ${CMAKE_SOURCE_DIR}/dependencies/protobuf/build/libprotobuf-lite.a
#                         ${CMAKE_SOURCE_DIR}/dependencies/protobuf/build/libprotoc.a
#                         ${CMAKE_SOURCE_DIR}/dependencies/protobuf/build/libupb.a)

# Get a list of all *.a files in the current directory 
# file(GLOB_RECURSE A_FILES "C:/Program Files (x86)/protobuf/lib/*.a")

# Create a library target and add the *.a files
# add_library(my_static_lib STATIC ${A_FILES})

# Link the library to your executable
# target_link_libraries(protobuf_cpp_mukbo_writer my_static_lib)
# set_target_properties(my_static_lib PROPERTIES LINKER_LANGUAGE CXX)
