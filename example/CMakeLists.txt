add_executable(example main.cpp)

target_link_libraries(example PRIVATE mUI::mUI)

install(
  TARGETS example
  RUNTIME DESTINATION bin
)
