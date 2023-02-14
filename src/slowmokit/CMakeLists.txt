# Recurse into methods/ to get the definitions of any bindings.
#add_subdirectory(methods)

# At install time, we simply install the src/ directory to include/
install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/../slowmokit.hpp"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/base.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/core.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/prereqs.hpp"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit/")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/methods" DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")