# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I.

# File definitions
TARGET = cal.exe
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
DEPS = $(patsubst %.o, %.d, $(OBJECTS))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Compile source files into object files and generate dependencies
# -MMD creates dependency files (.d)
# -MP adds phony targets for headers to prevent errors if a header is removed
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Include all dependency files
-include $(DEPS)

# Clean up build artifacts
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(DEPS)
# Phony targets are targets that don't represent actual files
.PHONY: all clean