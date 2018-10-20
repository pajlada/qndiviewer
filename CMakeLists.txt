cmake_minimum_required (VERSION 2.6)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project (QNDIViewer)
add_executable(QNDIViewer
    src/main.cpp
    src/messagequeue.cpp
    src/application.cpp
    src/ndifinder.cpp
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

find_package(NDI REQUIRED)

target_link_libraries(QNDIViewer "${NDI_SDK_Path}/lib/x86_64-linux-gnu/libndi.so")
link_directories("${NDI_SDK_Path}/lib/x86_64-linux-gnu")
message("${NDI_SDK_Path}/lib/x86_64-linux-gnu")
target_include_directories(QNDIViewer PUBLIC "${NDI_SDK_Path}/include")
# target_link_libraries (QNDIViewer ${NDI_Libraries})
