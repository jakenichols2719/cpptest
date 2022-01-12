#include "../munit/munit.h"
#include "../headers/ex.h"

static MunitResult testExampleStruct (const MunitParameter params[], void* data) {
    // Compiler complains if params/data not used.
    (void) params;
    (void) data;
    example_struct a = createExampleStruct(0,1);
    munit_assert(a.a == 0);
    munit_assert(a.b == 1);
    return MUNIT_OK;
}

static MunitTest suite_tests[] = {
    // Block for each test
    {
        (char*)"ExampleStruct", // Test Name
        testExampleStruct, // Test Performed
        NULL, // Setup
        NULL, // Teardown
        MUNIT_TEST_OPTION_NONE, // Test Options
        NULL
    }
};

static const MunitSuite suite = {
    (char*)"", // Test Suite Name
    suite_tests, // Tests
    NULL, // Other Suites
    1, // Number of Runs
    MUNIT_SUITE_OPTION_NONE // Options
};

// MUST DEFINE TEST_MAIN AROUND TEST MAIN FUNCTION
// OR GCC WILL BE ANGRY AT YOU
#ifdef TEST_MAIN
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, (void*) "µnit", argc, argv);
}
#endif
