project(lsconfig)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

aux_source_directory(src/ls SRC)
aux_source_directory(sample SRC_SAMPLE)

include_directories(include)

add_library(lsconfig SHARED ${SRC})
add_executable(testcase ${SRC} ${SRC_SAMPLE})

target_link_libraries(testcase lsjson lsitem lscopyableitem lsbuffer lscstring lsexception lsio lsfile lslogger lstime)

install(TARGETS lsconfig DESTINATION lib)

install(DIRECTORY include/ls DESTINATION include/)
