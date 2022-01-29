#include "headers/cpptest.h"

/**
 * @brief Construct a new Runnable Test
 * 
 * @param test_name Test name used in TestManager::RunAll() output
 */
RunnableTest::RunnableTest(std::string test_name) {
    name_ = test_name;
}

/**
 * @brief Get the name of the test
 * 
 * @return std::string Name of the test
 */
std::string RunnableTest::name() { return name_; }

/**
 * @brief Create a new test and return a pointer to it
 * 
 * @param test_name The name of the test to be created--see RunnableTest::RunnableTest(std::string test_name)
 * @return RunnableTest* A pointer to the created test; use to assign a lambda to Run
 */
RunnableTest* TestManager::NewTest(std::string test_name) {
    // Extend the name column spacing if new name is longest
    for(size_t n=namecol_spacing_.length(); n<test_name.length(); n++) {
        namecol_spacing_ += " ";
    }
    // Create the new test
    RunnableTest t (test_name);
    tests_.push_back(t);
    return &tests_[tests_.size()-1];
}

/**
 * @brief Run every test created by this TestManager
 * Runs all tests, output formatted as 'name | Passed/Not Passed'
 */
void TestManager::RunAll() {
    for(size_t n=0; n<tests_.size(); n++) {
        std::cout << tests_[n].name() << namecol_spacing_.erase(0,tests_[n].name().length()) << " | ";
        bool pass = tests_[n].Run();
        if(pass) { std::cout << "Passed" << std::endl; }
        else { std::cout << "Not Passed" << std::endl; }
    }
}