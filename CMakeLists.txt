cmake_minimum_required(VERSION 3.10)
project(cpp_sfml_template VERSION 1.0.0 LANGUAGES CXX)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
find_package(Threads REQUIRED)

if(UNIX)
   find_package(spdlog REQUIRED)
   find_package(jsoncpp REQUIRED)
endif()

if(WIN32)
   set(WIN32_GUI WIN32)
endif()

set(SFML_LIBS sfml-graphics sfml-system sfml-window)

file(GLOB SOURCES src/*.cpp)

if(NOT UNIX)
   add_subdirectory("vendor/jsoncpp")
   add_subdirectory("vendor/spdlog")
endif()

add_executable(${PROJECT_NAME} ${WIN32_GUI} ${SOURCES})

if(UNIX)
   target_link_libraries(${PROJECT_NAME} ${SFML_LIBS} spdlog::spdlog jsoncpp_lib)
   target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
else()
   target_link_libraries(${PROJECT_NAME} ${SFML_LIBS} jsoncpp_lib spdlog)
   target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib" "${PROJECT_SOURCE_DIR/vendor/jsoncpp}" "${PROJECT_SOURCE_DIR/vendor/spdlog}")
endif()

set(SFML_LIBS sfml-system sfml-window sfml-graphics)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# Copy res dir to the binary directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# copy config.json
file(COPY conf.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(MSVC)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
   endforeach()
endif()