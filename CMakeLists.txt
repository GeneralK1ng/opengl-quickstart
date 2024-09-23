cmake_minimum_required(VERSION 3.26)
project(Freeglut_Template)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/opengl/include)

# 链接库目录
link_directories(${PROJECT_SOURCE_DIR}/opengl/lib/x64)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# 添加可执行文件
add_executable(Freeglut_Template ${SRC_FILES})

# 链接系统库和外部库
target_link_libraries(Freeglut_Template PRIVATE
        ${PROJECT_SOURCE_DIR}/opengl/lib/x64/libfreeglut.a
        opengl32
        glu32
)

add_custom_command(TARGET Freeglut_Template POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/opengl/bin/x64/freeglut.dll
        $<TARGET_FILE_DIR:Freeglut_Template>)

