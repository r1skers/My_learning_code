# This Makefile is now a tutorial.
# 这个 Makefile 现在是一个教程。

# --- Variables --- #
# --- 变量区 --- #

# `CC` is the variable for the C compiler.
# `CC` 是用于C编译器的变量。
CC = gcc

# `CFLAGS` holds the compiler flags. These are options passed to the compiler.
# `CFLAGS` 用于存放编译器标志。这些是传递给编译器的选项。
# -Wall: Show all warnings (very recommended!)
# -Wall: 显示所有警告（强烈推荐！）。
# -Wextra: Show even more warnings.
# -Wextra: 显示额外的警告。
# -std=c99: Use the C99 standard for the language.
# -std=c99: 使用C99语言标准。
# -g: Include debugging information in the executable (for tools like gdb).
# -g: 在可执行文件中包含调试信息（供gdb等工具使用）。
BASE_CFLAGS = -Wall -Wextra -std=c99 -g

# --- Original Calculator App Rules ---
# --- 原始计算器应用的规则 --- #

CALC_TARGET = calculator_app
CALC_SOURCES = main.c calculator.c
CALC_OBJECTS = $(CALC_SOURCES:.c=.o)

# --- Tutorial App Rules ---
# --- 教程应用的规则 --- #

TUTORIAL_TARGET = tutorial_app
TUTORIAL_SOURCES = tutorial_main.c tutorial_config.c tutorial_hardware.c
TUTORIAL_OBJECTS = $(TUTORIAL_SOURCES:.c=.o)

# --- Build Configuration Logic ---
# --- 构建配置逻辑 --- #

# This is where the `-D` flag is used to control the build.
# 这里是使用 `-D` 标志来控制构建的地方。
# We check for variables passed from the command line, like `make build=debug`.
# 我们检查从命令行传递的变量，例如 `make build=debug`。

# Default build type is 'release'
# 默认的构建类型是 'release'（发布版）。
BUILD_TYPE = release
ifeq ($(build), debug)
    BUILD_TYPE = debug
endif

# Set flags based on the build type
# 根据构建类型设置标志
ifeq ($(BUILD_TYPE), debug)
    # In debug mode, we add -DDEBUG and set the version and log level.
    # 在调试模式下，我们添加 -DDEBUG 并设置版本和日志级别。
    TUTORIAL_CFLAGS = $(BASE_CFLAGS) -DDEBUG -DVERSION="1.1-debug" -DLOG_LEVEL=3
else
    # In release mode, we add optimizations (-O2) and set different macros.
    # 在发布模式下，我们添加优化选项 (-O2) 并设置不同的宏。
    TUTORIAL_CFLAGS = $(BASE_CFLAGS) -O2 -DVERSION="1.1-release" -DLOG_LEVEL=1
endif


# --- Targets and Rules ---
# --- 目标和规则 --- #

# `.PHONY` tells `make` that these targets are not actual files.
# `.PHONY` 告诉 `make` 这些目标不是真正的文件。
# This prevents `make` from getting confused if a file named `all` or `clean` exists.
# 这可以防止在存在名为 `all` 或 `clean` 的文件时 `make` 发生混淆。
.PHONY: all tutorial clean

# `all` is the default target. If you just run `make`, this is what it will do.
# `all` 是默认目标。如果你只运行 `make`，这就是它将执行的操作。
all: $(CALC_TARGET)

# Rule to build the original calculator app.
# 构建原始计算器应用的规则。
$(CALC_TARGET): $(CALC_OBJECTS)
	$(CC) $(BASE_CFLAGS) -o $(CALC_TARGET) $(CALC_OBJECTS)

# Rule to build the new tutorial app.
# 构建新教程应用的规则。
# You run this with `make tutorial` or `make tutorial build=debug`.
# 你可以通过 `make tutorial` 或 `make tutorial build=debug` 来运行它。
tutorial: $(TUTORIAL_TARGET)

# Linking rule for the tutorial app.
# 教程应用的链接规则。
# It takes all the tutorial's .o files and links them into the final executable.
# 它将教程所有的 .o 文件链接成最终的可执行文件。
$(TUTORIAL_TARGET): $(TUTORIAL_OBJECTS)
	@echo "--- Linking Tutorial App (Mode: $(BUILD_TYPE)) ---"
	@echo "--- 正在链接教程应用 (模式: $(BUILD_TYPE)) ---"
	$(CC) $(TUTORIAL_CFLAGS) -o $(TUTORIAL_TARGET) $(TUTORIAL_OBJECTS)
	@echo "--- Build complete. Run with: ./$(TUTORIAL_TARGET) ---"
	@echo "--- 构建完成。请运行: ./$(TUTORIAL_TARGET) ---"


# --- Pattern Rules ---
# --- 模式规则 --- #

# This is a pattern rule. It tells `make` how to create any `.o` file from a `.c` file.
# 这是一个模式规则。它告诉 `make` 如何从任意一个 `.c` 文件创建对应的 `.o` 文件。
# `%.o` matches any file ending in .o (the target).
# `%.o` 匹配任何以 .o 结尾的文件（目标）。
# `%.c` matches the corresponding file ending in .c (the prerequisite).
# `%.c` 匹配相应的以 .c 结尾的文件（依赖）。
#
# Automatic Variables used here:
# 这里使用的自动化变量：
# `$@`: The name of the target (`something.o`).
# `$@`: 目标文件的名称 (`something.o`)。
# `$<`: The name of the first prerequisite (`something.c`).
# `$<`: 第一个依赖文件的名称 (`something.c`)。
# `$^`: The names of all prerequisites.
# `$^`: 所有依赖文件的名称。

%.o: %.c
	@echo "Compiling $< -> $@"
	@echo "正在编译 $< -> $@"
	$(CC) $(TUTORIAL_CFLAGS) -c $< -o $@


# Rule to clean up all generated files.
# 清理所有生成文件的规则。
clean:
	@echo "Cleaning up generated files..."
	@echo "正在清理生成的文件..."
	rm -f $(CALC_OBJECTS) $(CALC_TARGET)
	rm -f $(TUTORIAL_OBJECTS) $(TUTORIAL_TARGET)