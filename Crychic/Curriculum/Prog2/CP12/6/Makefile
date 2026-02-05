CXX ?= g++
CXXFLAGS ?= -g -O2 -Wall -Wextra -std=c++17
TARGET := main.exe
SRCS := $(wildcard *.cpp) $(wildcard *.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	.\$(TARGET)

clean:
	-del /Q $(TARGET)
