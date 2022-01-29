# cpptest

## Description

A very basic c++ testing suite using <function> and lambda expressions to create and run tests.

## Setup

Add as a git submodule and include `cpptest/src/headers/cpptest.h` and everything is set. Alternatively,
you can download the src folder and include it directly--either way, including and compiling with
`cpptest.h` will allow test creation.

## Usage

Below is a template for creating a test manager, a basic test, and then running it.

```
TestManager tman;
tman.NewTest("Test")->Run = []() {
    assert(/*insert statement here*/)
    assert(/*insert statement here*/)
    assert(/*insert statement here*/)
    return true;
}
tman.RunAll();
```

## Contribution

If you want to modify this, I just ask that you follow usual GitHub ettiquite and not merge to main.
Otherwise, go wild--the purpose of this project is for me to have my own testing suite to use for class,
so I'm not bothered by other people doing what they want with it as long as the just-my-edits copy sticks
around.

## Boilerplate Notes (DO NOT REMOVE)

This project is built on a boilerplate setup created by Jake Nichols (109450366), specifically for
CSCI 3753 and 3010 at CU Boulder, but generally functional for C programming. It provides
testing functionality, formatting, and linting to create readable, consistent, and working code.
The base setup can be found at their GitHub page here. Please see the license for usage information.
