cmake_minimum_required(VERSION 3.16)
cmake_policy(VERSION 3.16)

project(cpplearn)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    message("Not tested on a Windows System proceed with caution")
endif()

set(courses
        c01
        c02)

set(c01
        m01
        m02
        m03
        m04
        m05
        m06
        m07
        m08
        m09
        m10
        m11
        m12
        m13
        m14
        m15
        m16
        m17
        m18
        m19
        m20
        m21
        m22
        m23
        m24
        m25
        m26)

set(c02
        m01
        m02
        m03
        m04
        m05
        m06
        m07
        m08
        m09
        m10)

macro(makeLink src dest target)
    add_custom_command(TARGET ${target} POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${src} ${dest}  DEPENDS  ${dest} COMMENT "mklink ${src} -> ${dest}")
endmacro()

foreach(course ${courses})
    foreach(module ${${course}})
        file(GLOB srcs
                "${course}/src/${module}/*.h"
                "${course}/src/${module}/*.cpp")
        set(name ${course}__${module})
        add_executable(${name} ${srcs})
        set_target_properties(${name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${course}")
    endforeach(module)
endforeach(course)
