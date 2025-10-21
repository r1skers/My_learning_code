# Makefile for the Bracket Matcher project

# Compiler and compiler flags
# -Wall: Enables all compiler's warning messages.
# -g: Adds debugging information to the executable file.
CC = gcc
CFLAGS = -Wall -g

# The name of our final executable
TARGET = Bracket_Matcher.exe

# All the .c source files needed for the project
SRCS = main.c stack.c

# Automatically generate the object file names from the source files
# (e.g., main.c -> main.o)
OBJS = $(SRCS:.c=.o)

# The 'all' rule is the default one that runs when you just type 'make'
# It depends on the target executable.
all: $(TARGET)

# This rule explains how to build the target executable.
# It depends on all the object files.
# The command links all object files together.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# This is a pattern rule that tells make how to create a .o file from a .c file.
# $< is an automatic variable that means the first prerequisite (the .c file).
# $@ is an automatic variable that means the target (the .o file).
%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

# The 'clean' rule is used to delete all generated files.
clean:
	rm -f $(TARGET) $(OBJS)
# This tells make that 'all' and 'clean' are not actual files.
.PHONY: all clean
