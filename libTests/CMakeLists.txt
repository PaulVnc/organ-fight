
add_executable(tests tests.cpp "boss.cpp" "boss.h" "note.h" "note.cpp")

target_link_libraries(tests PUBLIC src box2d sfml-graphics sfml-audio nlohmann_json)

add_custom_target(copy-resources-libTests ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources
                   DEPENDS ${CMAKE_SOURCE_DIR}/resources
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_dependencies(tests copy-resources-libTests)
