cmake_minimum_required (VERSION 3.26)

project (oop2_ex03)
set (MY_AUTHORS "Dima_Nikonov")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (include/UI)
add_subdirectory (include/ObjectContainers)
add_subdirectory (include/Players)
add_subdirectory (include/PlayStates)
add_subdirectory (include/UnitsData)
add_subdirectory (include/GameObjects)
add_subdirectory (src)
add_subdirectory (src/UI)
add_subdirectory (src/ObjectContainers)
add_subdirectory (src/Players)
add_subdirectory (src/PlayStates)
add_subdirectory (src/UnitsData)
add_subdirectory (src/GameObjects)
add_subdirectory (resources)
add_subdirectory (resources/Heroes)
add_subdirectory (resources/Mobs)
add_subdirectory (resources/Projectiles)

include (cmake/Zip.cmake)

set (SFML_LOCATION "C:/SFML/SFML-2.6.0")
set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")

find_package (SFML 2.6 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics sfml-main)

include (cmake/SFML.cmake)

