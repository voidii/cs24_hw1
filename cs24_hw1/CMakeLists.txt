cmake_minimum_required (VERSION 3.3)

project (AlgSolution)

aux_source_directory(. SOURCE_FILES)

file(GLOB HEADER_FILES "*.h")

source_group("Header Files" ${HEADER_FILES})

source_group("Source Files" ${SOURCE_FILES})

add_definitions(-std=c++11)

add_executable(solution ${SOURCE_FILES} ${HEADER_FILES})