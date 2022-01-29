#ifndef CPP_TEST_H
#define CPP_TEST_H

#include <functional>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <string>


/**
 * @brief Class to run specific tests
 * Gives a lambda-assignable member run that is run by the TestManager
*/
class RunnableTest {
private:
    std::string name_;
    bool passed_;
public:
    RunnableTest(std::string test_name);
    std::string name();
    std::function<bool()> Run;
};

/**
 * @brief Class to manage RunnableTest
 * Allows creation of and batch-running of tests
 */
class TestManager {
private:
    std::vector<RunnableTest> tests_;
    std::string namecol_spacing_ = "";
public:
    RunnableTest* NewTest(std::string test_name);
    void RunAll();
};

#endif