# This Makefile is now a tutorial.

# --- Variables --- #

# `CC` is the variable for the C compiler.
CC = gcc

# `CFLAGS` holds the compiler flags. These are options passed to the compiler.
# -Wall: Show all warnings (very recommended!)
# -Wextra: Show even more warnings.
# -std=c99: Use the C99 standard for the language.
# -g: Include debugging information in the executable (for tools like gdb).
BASE_CFLAGS = -Wall -Wextra -std=c99 -g

# --- Original Calculator App Rules ---

CALC_TARGET = calculator_app
CALC_SOURCES = main.c calculator.c
CALC_OBJECTS = $(CALC_SOURCES:.c=.o)

# --- Tutorial App Rules ---

TUTORIAL_TARGET = tutorial_app
TUTORIAL_SOURCES = tutorial_main.c tutorial_config.c tutorial_hardware.c
TUTORIAL_OBJECTS = $(TUTORIAL_SOURCES:.c=.o)

# --- Build Configuration Logic ---

# This is where the `-D` flag is used to control the build.
# We check for variables passed from the command line, like `make build=debug`.

# Default build type is 'release'
BUILD_TYPE = release
ifeq ($(build), debug)
    BUILD_TYPE = debug
endif

# Set flags based on the build type
ifeq ($(BUILD_TYPE), debug)
    # In debug mode, we add -DDEBUG and set the version and log level.
    TUTORIAL_CFLAGS = $(BASE_CFLAGS) -DDEBUG -DVERSION="1.1-debug" -DLOG_LEVEL=3
else
    # In release mode, we add optimizations (-O2) and set different macros.
    TUTORIAL_CFLAGS = $(BASE_CFLAGS) -O2 -DVERSION="1.1-release" -DLOG_LEVEL=1
endif


# --- Targets and Rules ---

# `.PHONY` tells `make` that these targets are not actual files.
# This prevents `make` from getting confused if a file named `all` or `clean` exists.
.PHONY: all tutorial clean

# `all` is the default target. If you just run `make`, this is what it will do.
all: $(CALC_TARGET)

# Rule to build the original calculator app.
$(CALC_TARGET): $(CALC_OBJECTS)
	$(CC) $(BASE_CFLAGS) -o $(CALC_TARGET) $(CALC_OBJECTS)

# Rule to build the new tutorial app.
# You run this with `make tutorial` or `make tutorial build=debug`.
tutorial: $(TUTORIAL_TARGET)

# Linking rule for the tutorial app.
# It takes all the tutorial's .o files and links them into the final executable.
$(TUTORIAL_TARGET): $(TUTORIAL_OBJECTS)
	@echo "--- Linking Tutorial App (Mode: $(BUILD_TYPE)) ---"
	$(CC) $(TUTORIAL_CFLAGS) -o $(TUTORIAL_TARGET) $(TUTORIAL_OBJECTS)
	@echo "--- Build complete. Run with: ./$(TUTORIAL_TARGET) ---"


# --- Pattern Rules ---

# This is a pattern rule. It tells `make` how to create any `.o` file from a `.c` file.
# `%.o` matches any file ending in .o (the target).
# `%.c` matches the corresponding file ending in .c (the prerequisite).
#
# Automatic Variables used here:
# `$@`: The name of the target (`something.o`).
# `$<`: The name of the first prerequisite (`something.c`).
# `$^`: The names of all prerequisites.

%.o: %.c
	@echo "Compiling $< -> $@"
	$(CC) $(TUTORIAL_CFLAGS) -c $< -o $@


# Rule to clean up all generated files.
clean:
	@echo "Cleaning up generated files..."
	rm -f $(CALC_OBJECTS) $(CALC_TARGET)
	rm -f $(TUTORIAL_OBJECTS) $(TUTORIAL_TARGET)