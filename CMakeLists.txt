cmake_minimum_required(VERSION 3.22)
project(slowmokit C CXX)

# If we are not using Visual Studio, use the GNU install directories module.
# Otherwise set the values manually.
if (NOT MSVC)
    include(GNUInstallDirs)
else ()
    set(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
    set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
    set(CMAKE_INSTALL_MANDIR ${CMAKE_INSTALL_PREFIX}/man)
    set(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_PREFIX}/share/doc/slowmokit)
    set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)
endif ()

# Ensure that GCC is new enough, if the compiler is GCC.
if (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5)
    message(FATAL_ERROR "GCC version (${CMAKE_CXX_COMPILER_VERSION}) is too old! 5.x or newer is required.")
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/slowmokit)

add_library(slowmokit
        src/slowmokit.hpp
        src/slowmokit.cpp)