#include "headers/cpptest.h"

int main(int argc, char* argv[]) {
    TestManager tman;
    tman.NewTest("Test Test")->Run = []() {
        assert(true==true);
        return true;
    };
    tman.NewTest("Test Test 2")->Run = []() {
        assert(true==true);
        return true;
    };
    tman.RunAll();
    return 0;
}