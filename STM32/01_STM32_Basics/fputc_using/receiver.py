import serial

ser= serial.Serial('COM6', 115200, timeout=1)

print("开始监听 STM32 的数据...")
while True:
    line_bytes = ser.readline()  # 读取一行数据，直到遇到换行符
    if line_bytes:
        line = line_bytes.decode('utf-8').rstrip()  # 解码并去除末尾的换行符
        print(f"收到 STM32 发来的: {line}")
        if "warning" in line:
            print(">>> 警告！检测到异常！")
