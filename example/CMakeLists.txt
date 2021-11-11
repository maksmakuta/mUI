add_executable(calc main.cpp)

target_link_libraries(calc PRIVATE mUI::mUI)

install(
  TARGETS calc
  RUNTIME DESTINATION bin
)
