# Set flags, clean, etc. based on OS
# Windows
ifeq ($(OS),Windows_NT)
	CLEAN:= del build.exe test.exe
else
	UNAME_S:= $(shell uname -s)
# Linux
	ifeq($(UNAME_S),Linux)
		CLEAN:= rm build test
endif

# Basic, universal flags
DIR:= ./src
SRC:= $(wildcard $(DIR)/*.c $(DIR)/*.cpp)
TESTS:= $(wildcard $(DIR)/tests/*.c $(DIR)/tests/*.cpp)
MUNIT:= $(DIR)/munit/munit.c
CFLAGS:= -Wall -I($(DIR)) -I($(DIR)/headers) -I($(DIR)/munit)
BUILDFLAGS:= -DBUILD_MAIN
TESTFLAGS:= -DTEST_MAIN

all: $(SRC)
	make build
	make test

build: $(SRC)
	g++ -o $@ $^ $(CFLAGS) $(BUILDFLAGS)

test: $(SRC) $(TESTS) $(MUNIT)
	g++ -o $@ $^ $(CFLAGS) $(TESTFLAGS)

fmt: $(SRC)
	clang-format -i $^

doc: $(SRC)
	doxygen ./.doxygen-format
	
clean:
	$(CLEAN)