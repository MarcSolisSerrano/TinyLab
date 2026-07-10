
cmake_minimum_required (VERSION 3.12)

include("Utilities.cmake")


#set(MAIN_PROJECT_NAME ObjectSerialization)
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
set(SOURCE_DIR ${ROOT_DIR}/Source)
set(CODE_DIR ${SOURCE_DIR}/Code)
get_filename_component(MAIN_PROJECT_NAME "${ROOT_DIR}" NAME)

message(STATUS "ROOT = ${ROOT_DIR}")
message(STATUS "NAME = ${MAIN_PROJECT_NAME}")
message(STATUS "Source = ${SOURCE_DIR}")

project(${MAIN_PROJECT_NAME})

AddLibraryToCurrentProject(${ROOT_DIR} "${CODE_DIR}")
set_target_properties(${MAIN_PROJECT_NAME} PROPERTIES COMPILE_WARNING_AS_ERROR ON)
SetLibraryCppStandard(${MAIN_PROJECT_NAME} 20)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_options(${MAIN_PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/bigobj>)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set_target_properties(${MAIN_PROJECT_NAME} PROPERTIES CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
endif()
