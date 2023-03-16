cmake_minimum_required(VERSION 3.22)
project(slowmokit C CXX)

# compile options
option(DEBUG "Compile with debugging information." OFF)
option(PROFILE "Compile with profiling information." OFF)
option(BUILD_TESTS "Build tests. (Note: time consuming!)" OFF)
option(ARMA_EXTRA_DEBUG "Compile with extra Armadillo debugging symbols." OFF)
option(DOWNLOAD_DEPENDENCIES "Automatically download dependencies if not available." OFF)

# minimum library  versions required
set(ARMADILLO_VERSION "12.0.1")


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

# Include modules in the CMake directory.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

# Set the required flags for compilers
if (CMAKE_COMPILER_IS_GNUCC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # Ensure that we can't compile with clang 3.4, since this causes strange
    # issues.
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
        message(FATAL_ERROR "slowmokit does not build correctly with clang < 3.5.  "
                "Please upgrade your compiler and reconfigure.")
    endif ()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ftemplate-depth=1000")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

    # To remove unused functions warnings.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-function")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If we are using MSVC, we need /bigobj.
if (MSVC)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /Zm200 /Zc:__cplusplus")
endif ()

# If we are using MINGW, we need sections and big-obj, otherwise we create too
# many sections.
if (CMAKE_COMPILER_IS_GNUCC AND WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wa,-mbig-obj")
endif()

# If using clang, we have to link against libc++ depending on the
# OS (at least on some systems). Further, gcc sometimes optimizes calls to
# math.h functions, making -lm unnecessary with gcc, but it may still be
# necessary with clang.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (APPLE)
        # Detect OS X version. Use '/usr/bin/sw_vers -productVersion' to
        # extract V from '10.V.x'.
        execute_process(/usr/bin/sw_vers ARGS
                -productVersion OUTPUT_VARIABLE MACOSX_VERSION_RAW)
        string(REGEX REPLACE
                "([0-9]+)(\\.([0-9]+).*)*" "\\1"
                MACOSX_MAJOR_VERSION
                "${MACOSX_VERSION_RAW}")

        string(REGEX REPLACE
                "([0-9]+)(\\.([0-9]+).*)*" "\\3"
                MACOSX_MINOR_VERSION
                "${MACOSX_VERSION_RAW}")

        # OSX Lion (10.7) and OS X Mountain Lion (10.8) doesn't automatically
        # select the right stdlib.
        if (${MACOSX_MAJOR_VERSION} LESS 11 AND ${MACOSX_MINOR_VERSION} LESS 9)
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
            set(CMAKE_SHARED_LINKER_FLAGS
                    "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
            set(CMAKE_MODULE_LINKER_FLAGS
                    "${CMAKE_MODULE_LINKER_FLAGS} -stdlib=libc++")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        endif()
    endif()

    # Link everything with -lm.
    set(MLPACK_LIBRARIES ${MLPACK_LIBRARIES} "m")
    # Use -pthread, but not on OS X.
    if (NOT APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    endif ()
endif()

# If we're using gcc, then we need to link against pthreads to use std::thread
if (CMAKE_COMPILER_IS_GNUCC)
    find_package(Threads)
    set(MLPACK_LIBRARIES ${MLPACK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()

# Debugging CFLAGS.  Turn optimizations off; turn debugging symbols on.
if (DEBUG)
    if (NOT MSVC)
        add_definitions(-DDEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -ftemplate-backtrace-limit=0")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g -O0")
    endif()

    # mlpack uses it's own mlpack::backtrace class based on Binary File Descriptor
    # <bfd.h> and linux Dynamic Loader <libdl.h> and more portable version in future
    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        find_package(Bfd)
        find_package(LibDL)
        if (LIBBFD_FOUND AND LIBDL_FOUND)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic")
            set(MLPACK_INCLUDE_DIRS ${MLPACK_INCLUDE_DIRS} ${LIBBFD_INCLUDE_DIRS}
                    ${LIBDL_INCLUDE_DIRS})
            set(MLPACK_LIBRARIES ${MLPACK_LIBRARIES} ${LIBBFD_LIBRARIES}
                    ${LIBDL_LIBRARIES})
            add_definitions(-DMLPACK_HAS_BFD_DL)
        else()
            message(WARNING "No libBFD and/or libDL has been found!")
        endif()
    endif()
else()
    add_definitions(-DNDEBUG)
    if (NOT MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O3")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O3")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /O3")
    endif ()
endif()

# Profiling CFLAGS.  Turn profiling information on.
if (CMAKE_COMPILER_IS_GNUCC AND PROFILE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
endif()

# If the user asked for extra Armadillo debugging output, turn that on.
if (ARMA_EXTRA_DEBUG)
    add_definitions(-DARMA_EXTRA_DEBUG)
endif()

if (NOT DOWNLOAD_DEPENDENCIES)
    find_package(Armadillo "${ARMADILLO_VERSION}" REQUIRED)
else()
    find_package(Armadillo "${ARMADILLO_VERSION}")
    if (NOT ARMADILLO_FOUND)
        if (NOT CMAKE_CROSSCOMPILING)
            find_package(BLAS QUIET)
            find_package(LAPACK QUIET)
            if (NOT BLAS_FOUND AND NOT LAPACK_FOUND)
                message(FATAL_ERROR "Can not find BLAS or LAPACK!  These are required for Armadillo.  Please install one of them---or install Armadillo---before installing slowmokit.")
            endif()
        endif()
        # TODO: change the version to 12.0.1
        get_deps(http://files.mlpack.org/armadillo-10.3.0.tar.gz armadillo armadillo-10.3.0.tar.gz)
        set(ARMADILLO_INCLUDE_DIR ${GENERIC_INCLUDE_DIR})
        find_package(Armadillo REQUIRED)
    endif()
endif()
# Include directories for the previous dependencies.
set(SLOWMOKIT_INCLUDE_DIRS ${SLOWMOKIT_INCLUDE_DIRS} ${ARMADILLO_INCLUDE_DIRS})
set(SLOWMOKIT_LIBRARIES ${SLOWMOKIT_LIBRARIES} ${ARMADILLO_LIBRARIES})

# Detect OpenMP support in a compiler. If the compiler supports OpenMP, flags
# to compile with OpenMP are returned and added.  Note that MSVC does not
# support a new-enough version of OpenMP to be useful.
if (USE_OPENMP)
    find_package(OpenMP)
endif ()

if (OpenMP_FOUND AND OpenMP_CXX_VERSION VERSION_GREATER_EQUAL 3.0.0)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(MLPACK_LIBRARIES ${MLPACK_LIBRARIES} ${OpenMP_CXX_LIBRARIES})
else ()
    # Disable warnings for all the unknown OpenMP pragmas.
    if (NOT MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4068")
    endif ()
    set(OpenMP_CXX_FLAGS "")
endif ()

include_directories(BEFORE ${SLOWMOKIT_INCLUDE_DIRS})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# On Windows, things end up under Debug/ or Release/.
if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

    # Copy all necessary DLLs for runtime to the build directory.
    # This is a little hackish, but I can't figure out clear ways to make CMake
    # consistently link everything 100% statically across platforms or set the
    # runtime path right always, so this is the best I know how to do for now.
    foreach(dir ${DLL_COPY_DIRS})
        file(GLOB dir_dll_list "${dir}/*.dll")
        file(COPY ${dir_dll_list} DESTINATION ${CMAKE_BINARY_DIR}/Release/)
        file(COPY ${dir_dll_list} DESTINATION ${CMAKE_BINARY_DIR}/Debug/)
    endforeach ()

    foreach(file ${DLL_COPY_LIBS})
        file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/Release/)
        file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/Debug/)
    endforeach()
else ()
    # If not on Windows, put them under more standard UNIX-like places.  This is
    # necessary, otherwise they would all end up in
    # ${CMAKE_BINARY_DIR}/src/mlpack/methods/... or somewhere else random like
    # that.
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
endif ()

add_subdirectory(include/slowmokit)
