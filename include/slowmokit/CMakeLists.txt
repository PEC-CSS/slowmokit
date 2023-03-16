# At install time, we simply install the include/ directory to include/
install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/../slowmokit.hpp"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/base.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/core.hpp"
        DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/kits" DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/core" DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")