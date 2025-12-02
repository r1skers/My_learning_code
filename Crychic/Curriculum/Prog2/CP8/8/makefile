# 1. 定义编译器
CC = g++

# 2. 定义编译选项 (-Wall 显示警告, -g 方便调试)
CFLAGS = -Wall -g

# 3. 定义最终生成的可执行文件名
# Windows下可能需要叫 run_student.exe，但这里写 run_student 也没事
TARGET = run_student

# 4. 定义需要的目标文件 (.o)
OBJS = main.o student.o

# --- 核心规则 ---

# 链接：把所有的 .o 合成一个可执行文件
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# 编译 main.cpp
main.o: main.cpp student.h
	$(CC) $(CFLAGS) -c main.cpp

# 编译 student.cpp
student.o: student.cpp student.h
	$(CC) $(CFLAGS) -c student.cpp

# --- 新增的清理功能 ---

# .PHONY 的意思是告诉 make："clean" 只是个命令动作，不是一个文件名。
# 防止你万一文件夹里真有个叫 clean 的文件，导致冲突。
.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe