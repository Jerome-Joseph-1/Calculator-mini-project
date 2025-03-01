// tests/simple_test_framework.h
#ifndef SIMPLE_TEST_FRAMEWORK_H
#define SIMPLE_TEST_FRAMEWORK_H

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

class TestFramework {
private:
    struct TestCase {
        std::string name;
        std::function<bool(TestFramework&)> test;
    };
    
    std::vector<TestCase> tests;
    int passed = 0;
    int failed = 0;

public:
    template<typename Func>
    void addTest(const std::string& name, Func test) {
        tests.push_back({name, test});
    }
    
    bool expectEqual(double a, double b, double epsilon = 0.0001) {
        return std::fabs(a - b) < epsilon;
    }
    
    bool expectEqual(int a, int b) {
        return a == b;
    }
    
    bool expectEqual(long long a, long long b) {
        return a == b;
    }
    
    void runTests() {
        std::cout << "Running " << tests.size() << " tests...\n";
        
        for (const auto& test : tests) {
            std::cout << "Test: " << test.name << " ... ";
            bool result = test.test(*this);
            
            if (result) {
                std::cout << "PASSED\n";
                passed++;
            } else {
                std::cout << "FAILED\n";
                failed++;
            }
        }
        
        std::cout << "\nResults: " << passed << " passed, " << failed << " failed\n";
    }
    
    int getExitCode() {
        return failed > 0 ? 1 : 0;
    }
};

#endif // SIMPLE_TEST_FRAMEWORK_H