cmake_minimum_required(VERSION 3.15)

# module

project(bcrypt LANGUAGES C)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

file(GLOB SRC_FILES src/*.c)
file(GLOB HEADER_FILES include/*.h)

add_library(bcrypt SHARED ${SRC_FILES} ${HEADER_FILES})
target_include_directories(bcrypt PUBLIC include)

target_include_directories(bcrypt PUBLIC deps/module-sdk/include)
target_compile_features(bcrypt PRIVATE cxx_std_17)
set_target_properties(bcrypt PROPERTIES LINKER_LANGUAGE C)

if(WIN32)
    target_link_libraries(bcrypt PRIVATE "${CMAKE_SOURCE_DIR}/deps/module-sdk/lib/lua.lib" "ws2_32")
elseif(UNIX AND NOT APPLE)
    target_link_libraries(bcrypt PRIVATE "${CMAKE_SOURCE_DIR}/deps/module-sdk/lib/liblua.a")
endif()
