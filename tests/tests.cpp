#include "../src/BasicCalc/basic_calc.h"
#include "tests.h"

int main() {
    TestFramework tf;
    
    // Square Root Tests
    tf.addTest("Square Root of 4 should be 2", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.sqrt(4.0), 2.0);
    });
    
    tf.addTest("Square Root of 9 should be 3", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.sqrt(9.0), 3.0);
    });
    
    // Factorial Tests
    tf.addTest("Factorial of 0 should be 1", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.factorial(0), 1LL);
    });
    
    tf.addTest("Factorial of 5 should be 120", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.factorial(5), 120LL);
    });
    
    // Natural Log Tests
    tf.addTest("Natural Log of 1 should be 0", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.natural_log(1.0), 0.0);
    });
    
    tf.addTest("Natural Log of 2.718 should be near 1", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.natural_log(2.718), 1.0, 0.001);
    });
    
    // Power Tests
    tf.addTest("2^3 should be 8", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.pow(2.0, 3.0), 8.0);
    });
    
    tf.addTest("5^0 should be 1", [](TestFramework& tf) {
        basic_calc::BasicCalc calc;
        return tf.expectEqual(calc.pow(5.0, 0.0), 1.0);
    });

    // ADDING INVALID TEST
    // tf.addTest("5^0 should be 1", [](TestFramework& tf) {
    //     basic_calc::BasicCalc calc;
    //     return tf.expectEqual(calc.pow(5.0, 0.0), 12.0);
    // });
    
    tf.runTests();
    return tf.getExitCode();
}