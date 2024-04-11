cmake_minimum_required(VERSION 3.8)
project(gsynth)

find_package(OpenGL REQUIRED)

# GLFW build settings
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(glfw3_DIR libs/glfw/CMake)

add_subdirectory(libs/glfw/)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/glfw/include)
include_directories(${PROJECT_SOURCE_DIR}/libs/imgui)
include_directories(${PROJECT_SOURCE_DIR}/libs/imgui/backends)

# ImGui
set(IMGUI_PATH libs/imgui)
file(GLOB IMGUI_GLOB
    ${IMGUI_PATH}/imgui.h
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imconfig.h
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_internal.h
    ${IMGUI_PATH}/imstb_rectpack.h
    ${IMGUI_PATH}/imstb_textedit.h
    ${IMGUI_PATH}/imstb_truetype.h
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp

    # specific bindings...
    ${IMGUI_PATH}/backends/imgui_impl_glfw.h
    ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.h
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3_loader.cpp)

# Set source files
set(SOURCES 
    src/synthwindow.cpp
    src/main.cpp
    include/main.h
    include/synthwindow.h
    ${IMGUI_GLOB}
)

# Add executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})

# Link GLFW library
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw)
