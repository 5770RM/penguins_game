cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(game_gui)

# Set this to the minimal version you want to support
find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake

# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

  endif()

endif()

# This is the main part:

add_executable(${PROJECT_NAME} game_gui.c gui.c ../bots.c ../evaluation.c ../map.c ../miscellaneous.c ../movement.c ../placement.c)
#set(raylib_VERBOSE 1)
#target_link_directories(${PROJECT_NAME} PRIVATE ../)
target_link_libraries(${PROJECT_NAME} raylib)
#target_link_libraries(${PROJECT_NAME} raygui)

add_subdirectory(generic\ data\ containers/queue)
target_include_directories(${PROJECT_NAME} PUBLIC generic\ data\ containers/queue)
target_link_directories(${PROJECT_NAME} PRIVATE generic\ data\ containers/queue)
target_link_libraries(${PROJECT_NAME} queue)

add_subdirectory(generic\ data\ containers/stack)
target_include_directories(${PROJECT_NAME} PUBLIC generic\ data\ containers/stack)
target_link_directories(${PROJECT_NAME} PRIVATE generic\ data\ containers/stack)
target_link_libraries(${PROJECT_NAME} stack)

add_subdirectory(generic\ data\ containers/vector)
target_include_directories(${PROJECT_NAME} PUBLIC generic\ data\ containers/vector)
target_link_directories(${PROJECT_NAME} PRIVATE generic\ data\ containers/vector)
target_link_libraries(${PROJECT_NAME} vector)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# That's it! You should have an example executable that you can run. Have fun!
