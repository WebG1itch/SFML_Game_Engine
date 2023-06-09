cmake_minimum_required(VERSION 3.25)
project(SFML_Game_Engine)

set(CMAKE_CXX_STANDARD 23)

add_executable(SFML_Game_Engine main.cpp Core/GameLoop.cpp Core/GameLoop.h Core/Window.cpp Core/Window.h Core/EventManager.h Core/EventManager.cpp Util/Textbox.cpp Util/Textbox.h)

include_directories(headers /usr/include C:/SFML/include)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS window graphics audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy .dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLL "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()