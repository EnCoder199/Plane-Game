cmake_minimum_required(VERSION 3.16)

project(Template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/Plane-Game/*.cpp" # Runs the demo by default
                                     # Change to "${CMAKE_SOURCE_DIR}/src/YOUR_MAIN_FILE.cpp"
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
    src/core/CameraHandling.cpp)

target_include_directories(Template PRIVATE
    "${CMAKE_SOURCE_DIR}/lib"
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/src/core"
    "${CMAKE_SOURCE_DIR}/src/core/object"
)

if(APPLE)
    target_link_libraries(Template PRIVATE
        "${CMAKE_SOURCE_DIR}/lib/libraylib.a"
        "-framework CoreVideo"
        "-framework IOKit"
        "-framework Cocoa"
        "-framework GLUT"
        "-framework OpenGL"
    )
endif()

set_target_properties(Template PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)