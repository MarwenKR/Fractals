cmake_minimum_required(VERSION 3.0.0)
project(fractals VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
#add Eigen
include_directories(${CMAKE_SOURCE_DIR}/external/eigen)


# Add GLFW
add_subdirectory(external/glfw)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Set source files
set(SOURCE src/main.cpp)

# Add executables
add_executable(fractals ${SOURCE})

# Include directories
target_include_directories(fractals PUBLIC 
    external/glfw/include
    ${OPENGL_INCLUDE_DIR} # Include OpenGL headers
)

# Link libraries
target_link_libraries(fractals 
    glfw
    ${OPENGL_LIBRARIES} # Link OpenGL libraries
)
