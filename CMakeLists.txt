cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(Pong)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
include(FetchContent)
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

FetchContent_Declare(
    mini
    GIT_REPOSITORY https://github.com/pulzed/mINI
)
FetchContent_Populate(mini)
include_directories("${mini_SOURCE_DIR}/src/mini")

# Our Project
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ball.cpp
    src/paddle.cpp
    src/text.cpp
    src/settings/settings.cpp)

target_include_directories(Pong PUBLIC
  "${CMAKE_SOURCE_DIR}/src"
  "${CMAKE_SOURCE_DIR}/src/settings")
    #set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)
