cmake_minimum_required(VERSION 3.28)
project(FanumRPG)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(FanumRPG ${SOURCES} ${HEADERS})

target_link_libraries(FanumRPG
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)