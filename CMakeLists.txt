cmake_minimum_required(VERSION 3.7)
set(AssignmentNameHere raytracer)
project(${AssignmentNameHere})

set(CMAKE_CXX_STANDARD 11)
macro(pre_build TARGET_NAME)
    add_custom_target( ${TARGET_NAME}_PRE_BUILD ALL )
    message("STATUS" "current source dir in macro " ${CMAKE_CURRENT_SOURCE_DIR})
    add_custom_command(
            TARGET ${TARGET_NAME}_PRE_BUILD
            ${ARGN}
            PRE_BUILD
            COMMENT "${TARGET_NAME}_PRE_BUILD ..."
    )

    add_dependencies(${TARGET_NAME} ${TARGET_NAME}_PRE_BUILD)
endmacro()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)
include_directories("ext/glm/"
        "ext/glfw/include"
	"ext/glew/include"
	"ext/DevIL/include"
        )
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(ext/glew/build/cmake)
add_subdirectory(ext/glfw)
add_subdirectory(ext/DevIL)

set(PLATFORM_LINK )
if (UNIX)
    set(PLATFORM_LINK -ldl)
endif (UNIX)

file(GLOB SRC_CPP "src/*.cpp")
file(GLOB SRC_HDR "src/*.h")
set(SOURCE_FILES ${SRC_CPP} ${SRC_HDR})
#TODO add your source files here
set(SOURCE_FILES src/main.cpp ${SRC_CPP} ${SRC_HDR})

add_executable(${AssignmentNameHere} ${SOURCE_FILES} ${DEPS_SOURCES})
target_link_libraries(${AssignmentNameHere} glfw ${GLFW_LIBRARIES} ${PLATFORM_LINK})
target_link_libraries(${AssignmentNameHere} glew ${GLEW_LIBRARIES} ${PLATFORM_LINK})
if (APPLE)
	target_link_libraries(${AssignmentNameHere} il ${IL_LIBRARIES} ${PLATFORM_LINK})
elseif (UNIX)
	target_link_libraries(${AssignmentNameHere} IL ${IL_LIBRARIES} ${PLATFORM_LINK})
endif (APPLE)

pre_build(${AssignmentNameHere}
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin/Resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory   ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_CURRENT_SOURCE_DIR}/bin/Resources)