# CMake generated Testfile for 
# Source directory: /home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example
# Build directory: /home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Runs "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "25")
set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;194;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Usage "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial")
set_tests_properties(Usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:.*number" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;195;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp4 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "4")
set_tests_properties(Comp4 PROPERTIES  PASS_REGULAR_EXPRESSION "4 is 2" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;205;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp9 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "9")
set_tests_properties(Comp9 PROPERTIES  PASS_REGULAR_EXPRESSION "9 is 3" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;206;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp5 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "5")
set_tests_properties(Comp5 PROPERTIES  PASS_REGULAR_EXPRESSION "5 is 2.236" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;207;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp7 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "7")
set_tests_properties(Comp7 PROPERTIES  PASS_REGULAR_EXPRESSION "7 is 2.645" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;208;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp25 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "25")
set_tests_properties(Comp25 PROPERTIES  PASS_REGULAR_EXPRESSION "25 is 5" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;209;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp-25 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "-25")
set_tests_properties(Comp-25 PROPERTIES  PASS_REGULAR_EXPRESSION "-25 is (-nan|nan|0)" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;210;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
add_test(Comp0.0001 "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/build/Tutorial" "0.0001")
set_tests_properties(Comp0.0001 PROPERTIES  PASS_REGULAR_EXPRESSION "0.0001 is 0.01" _BACKTRACE_TRIPLES "/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;200;add_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;211;do_test;/home/ngpong/CMake/Help/guide/importing-exporting/0x1:tutorial_complete_example/CMakeLists.txt;0;")
subdirs("MathFunctions")
