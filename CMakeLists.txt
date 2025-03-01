cmake_minimum_required(VERSION 3.10)
project(ScientificCalculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/BasicCalc
    # ${CMAKE_SOURCE_DIR}/src/ExpressionEvaluator
    ${CMAKE_SOURCE_DIR}/tests
)

add_executable(calculator
    src/main.cpp
    src/BasicCalc/basic_calc.cpp
    # src/ExpressionEvaluator/expression_eval.cpp
)

add_executable(calculator_test 
    tests/tests.cpp
    src/BasicCalc/basic_calc.cpp
    # src/ExpressionEvaluator/expression_eval.cpp
)

enable_testing()
add_test(NAME calculator_tests COMMAND calculator_test)