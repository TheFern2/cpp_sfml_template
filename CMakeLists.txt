cmake_minimum_required(VERSION 3.25)
project(cpp_sfml_template VERSION 1.0.1 LANGUAGES CXX)

# Global C++ standard (applies to all targets unless overridden)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default to Release builds if none specified
if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

# Dependencies
find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
find_package(Threads REQUIRED)

# On Unix/Homebrew, prefer package configs
if (UNIX)
   find_package(spdlog REQUIRED)
   find_package(jsoncpp CONFIG REQUIRED)  # Homebrew provides a CMake config
endif()

# Windows vendoring fallback (if you really need it)
if (WIN32)
   set(WIN32_GUI WIN32)
endif()

# Sources
file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Executable
add_executable(${PROJECT_NAME} ${WIN32_GUI} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link libraries
if (UNIX)
   target_link_libraries(${PROJECT_NAME}
           PRIVATE
           sfml-graphics sfml-window sfml-system
           spdlog::spdlog
           jsoncpp_lib
           Threads::Threads
   )
else()
   # If you vendor these libs on Windows, adjust as needed:
   add_subdirectory(vendor/jsoncpp)
   add_subdirectory(vendor/spdlog)

   target_link_libraries(${PROJECT_NAME}
           PRIVATE
           sfml-graphics sfml-window sfml-system
           jsoncpp_lib
           spdlog
           Threads::Threads
   )
endif()

# Optional: generate compile_commands.json for debugging toolchains/flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Runtime assets
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/conf.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# (Optional) MSVC-only DLL copy — keep if you actually need it
if (MSVC)
   set(SFML_LIBS sfml-system sfml-window sfml-graphics)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      if (lib_path)
         file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
      endif()
   endforeach()
endif()