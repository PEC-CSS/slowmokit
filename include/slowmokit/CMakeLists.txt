# At install time, we simply install the src/ directory to include/
install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/../slowmokit.hpp"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/core.hpp"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/" DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/slowmokit")