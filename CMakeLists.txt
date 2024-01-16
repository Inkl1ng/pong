cmake_minimum_required(VERSION 3.16)
project(pong-SFML LANGUAGES CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
# project
add_executable(pong
    src/main.cpp
    src/Main_menu.cpp
    src/Ball.cpp
    src/Game.cpp
    src/Paddle.cpp
    src/util/Asset_manager.cpp
    src/util/Text.cpp
    src/bot/Bot.cpp
)

# copy data directory to binary directory so the executable will be able to find it
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# message("data direcotry copied to binary direcotry")

# for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# dependencies
# SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

target_link_libraries(pong PRIVATE sfml-graphics sfml-audio sfml-system sfml-window)
target_compile_features(pong PRIVATE cxx_std_17)

# platform specific
if(WIN32)
    add_custom_command(
        TARGET pong
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:pong>
        VERBATIM)
endif()
install(TARGETS pong)

if(MSVC)
  target_compile_options(pong PUBLIC "/ZI")
  target_link_options(pong PUBLIC "/INCREMENTAL")
endif()

