cmake_minimum_required(VERSION 3.10)
project(PracticeCPP VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/AdvancedCPP/09_Project_numword)

# Function to create executables
function(create_executables category)
    foreach(src IN ITEMS ${ARGN})
        # Skip files that need special handling
        if(src MATCHES "numword\\.cpp$" OR src MATCHES "numword-test\\.cpp$")
            continue()
        endif()
        
        if(NOT IS_ABSOLUTE "${src}")
            set(src "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
        endif()
        
        if(NOT EXISTS "${src}")
            message(WARNING "Source file not found: ${src}")
            continue()
        endif()
        
        get_filename_component(target_name "${src}" NAME_WE)
        set(full_target "${category}_${target_name}")
        
        add_executable(${full_target} "${src}")
        message(STATUS "Created target: ${full_target}")
        
        target_compile_features(${full_target} PRIVATE cxx_std_20)
    endforeach()
endfunction()

# Get source files
file(GLOB_RECURSE THEBASICS_SOURCES TheBasics/*.cpp)
file(GLOB_RECURSE DESIGNPATTERN_SOURCES DesignPattern/*.cpp)
file(GLOB_RECURSE ADVANCEDCPP_SOURCES AdvancedCPP/*.cpp)

# Create regular executables
create_executables(TheBasics ${THEBASICS_SOURCES})
create_executables(DesignPattern ${DESIGNPATTERN_SOURCES})
create_executables(AdvancedCPP ${ADVANCEDCPP_SOURCES})

# Handle numword as a library
add_library(AdvancedCPP_numword STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/AdvancedCPP/09_Project_numword/numword.cpp
)
target_include_directories(AdvancedCPP_numword PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/AdvancedCPP/09_Project_numword
)

# Create numword-test executable with proper linking
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/AdvancedCPP/09_Project_numword/numword-test.cpp)
    add_executable(AdvancedCPP_numword-test 
        ${CMAKE_CURRENT_SOURCE_DIR}/AdvancedCPP/09_Project_numword/numword-test.cpp
    )
    target_link_libraries(AdvancedCPP_numword-test PRIVATE AdvancedCPP_numword)
    target_compile_features(AdvancedCPP_numword-test PRIVATE cxx_std_20)
    message(STATUS "Created special target: AdvancedCPP_numword-test")
endif()

# Print all targets
get_property(all_targets DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)
message(STATUS "=== Total targets created: ===")
foreach(t ${all_targets})
    get_target_property(target_type ${t} TYPE)
    message(STATUS "  - ${t} (${target_type})")
endforeach()