cmake_minimum_required(VERSION 3.16)

# FIXED: Enforcing both C and CXX allows FetchContent to compile raylib natively anywhere
project(Template LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- AUTOMATIC CROSS-PLATFORM RAYLIB FETCHING ---
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib" # <-- Added explicit quotes
    GIT_TAG        "5.5"
)
set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)
# ------------------------------------------------


file(GLOB SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/Plane-Game/*.cpp"
)

add_executable(Template ${SOURCES}
    src/core/Keyhandle.hpp
    src/core/Keyhandle.cpp
    src/core/object/MutableObject.hpp
    src/core/object/MutableObject.cpp
    src/core/object/Collision.hpp
    src/core/object/Collision.cpp
    src/core/object/Rotation.hpp
    src/core/Window.hpp
    src/core/Window.cpp
    Plane-Game/Player.hpp
    Plane-Game/Player.cpp
    src/core/Logging.hpp
    src/core/CameraHandling.hpp
    src/core/CameraHandling.cpp
)

target_include_directories(Template PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/src/core"
    "${CMAKE_SOURCE_DIR}/src/core/object"
    "${raylib_SOURCE_DIR}/src" # <-- ADD THIS LINE
)


# This target includes everything needed for Windows, Mac, and Linux build chains automatically
target_link_libraries(Template PRIVATE raylib)

set_target_properties(Template PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
