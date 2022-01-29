# Project source code directory
DIR:= ./src
# Set flags, clean, etc. based on OS
# Windows
ifeq ($(OS),Windows_NT)
	CLEAN:= del build.exe test.exe
	INCLUDE:= -I($(DIR)) -I($(DIR)/headers) -I($(DIR)/munit)
else
	UNAME_S:= $(shell uname -s)
# Linux
	ifeq ($(UNAME_S),Linux)
		CLEAN:= rm build test
		INCLUDE:= -I/$(DIR) -I/$(DIR)/headers -I/$(DIR)/munit
	endif
endif

# Basic, universal flags
SRC:= $(wildcard $(DIR)/headers/*.h $(DIR)/*.h $(DIR)/*.c $(DIR)/*.cpp)
CFLAGS:= -Wall -std=c++11 $(INCLUDE)
BUILDFLAGS:= -DBUILD_MAIN
TESTFLAGS:= -DTEST_MAIN

all: $(SRC)
	make build

build: $(SRC)
	g++ -o $@ $^ $(CFLAGS) $(BUILDFLAGS)

fmt: $(SRC)
	clang-format -i $^

doc: $(SRC)
	doxygen ./.doxygen-format
	
clean:
	$(CLEAN)