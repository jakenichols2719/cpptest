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
SRC:= $(wildcard $(DIR)/*.c)
TESTS:= $(wildcard $(DIR)/*.c $(DIR)/tests/*.c)
MUNIT:= $(DIR)/munit/munit.c
CFLAGS:= -Wall -I($(DIR)) -I($(DIR)/headers) -I($(DIR)/munit)
BUILDFLAGS:= -DBUILD_MAIN
TESTFLAGS:= -DTEST_MAIN

build: $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(BUILDFLAGS)

test: $(TESTS) $(MUNIT)
	gcc -o $@ $^ $(CFLAGS) $(TESTFLAGS)

fmt: $(SRC)
	clang-format -i $^
	
clean:
	$(CLEAN)