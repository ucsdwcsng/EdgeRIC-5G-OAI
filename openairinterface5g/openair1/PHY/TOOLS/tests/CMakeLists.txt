add_executable(test_signal_energy test_signal_energy.cpp ../signal_energy.c)
target_link_libraries(test_signal_energy PRIVATE GTest::gtest UTIL)
add_dependencies(tests test_signal_energy)
add_test(NAME test_signal_energy
  COMMAND ./test_signal_energy)
