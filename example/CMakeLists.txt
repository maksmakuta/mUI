add_executable(calc calc.cpp)

target_link_libraries(calc PRIVATE mUI::mUI)

install(
  TARGETS calc
  RUNTIME DESTINATION bin
)
