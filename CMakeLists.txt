cmake_minimum_required(VERSION 3.16)

# FIXED: Enforcing both C and CXX allows FetchContent to compile raylib natively anywhere
project(Template LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(RAYLIB_SOURCE_DIR "" CACHE PATH
    "Path to a local raylib checkout for offline builds")
if(RAYLIB_SOURCE_DIR)
    add_subdirectory("${RAYLIB_SOURCE_DIR}" "${CMAKE_BINARY_DIR}/raylib-build"
                     EXCLUDE_FROM_ALL)
    set(RAYLIB_INCLUDE_DIR "${RAYLIB_SOURCE_DIR}/src")
else()
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL "https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz"
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(raylib)
    set(RAYLIB_INCLUDE_DIR "${raylib_SOURCE_DIR}/src")
endif()

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/Game/*.cpp"
)
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/tests/*.cpp"
)

add_executable(Template ${CORE_SOURCES} ${GAME_SOURCES})

target_include_directories(Template PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/src/core"
    "${CMAKE_SOURCE_DIR}/src/core/object"
    "${RAYLIB_INCLUDE_DIR}"
)

target_link_libraries(Template PRIVATE raylib)

if(CMAKE_CXX_COMPILER_ID MATCHES "AppleClang|Clang|GNU")
    target_compile_options(Template PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_executable(CoreTests ${TEST_SOURCES} ${CORE_SOURCES})
target_include_directories(CoreTests PRIVATE
    "${CMAKE_SOURCE_DIR}/src/core"
    "${CMAKE_SOURCE_DIR}/src/core/object"
    "${RAYLIB_INCLUDE_DIR}"
)
target_link_libraries(CoreTests PRIVATE raylib)
if(CMAKE_CXX_COMPILER_ID MATCHES "AppleClang|Clang|GNU")
    target_compile_options(CoreTests PRIVATE -Wall -Wextra -Wpedantic)
endif()
add_test(NAME CoreTests COMMAND CoreTests)

set_target_properties(Template PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
