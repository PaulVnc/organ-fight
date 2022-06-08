
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "movingObject.cpp" "movingObject.h" "note.cpp" "note.h" "character.h")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC box2d sfml-graphics sfml-audio nlohmann_json)