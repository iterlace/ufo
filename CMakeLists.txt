cmake_minimum_required(VERSION 3.17)
project(ufo)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/library.cpp src/library_test.cpp
        include/library.h src/logger.cpp src/logger.h src/utils.cpp src/utils.h )
set(PUBLIC_HEADERS include/library.h)
add_library(ufo ${SOURCE_FILES})
add_subdirectory(tests)
set_target_properties(ufo PROPERTIES VERSION "${PROJECT_VERSION}" PUBLIC_HEADER "${PUBLIC_HEADERS}")
target_include_directories(ufo PRIVATE .)

set(CMAKE_SHARED_LINKER_FLAGS "-Wall")

# configure_file(mylib.pc.in mylib.pc @ONLY)
install(TARGETS ufo
        ARCHIVE DESTINATION ./${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ./${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
# install(FILES ${CMAKE_BINARY_DIR}/mylib.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)