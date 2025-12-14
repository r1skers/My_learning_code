import serial # type: ignore

# 1. 打开串口 (就像你打开串口助手一样)
# 注意：COM口号要改成你电脑上实际显示的，波特率要和 STM32 设置的一样
ser = serial.Serial('COM6', 115200, timeout=1)

print("开始监听 STM32 的数据...")

while True:
    # 2. 读取数据
    if ser.in_waiting: # 如果有数据在排队
        # read_all() 读出来是字节 (bytes)，比如 b'Hello'
        # decode() 把字节解码成字符串
        data = ser.read_all().decode('utf-8') 
        
        print(f"收到 STM32 发来的: {data}")

        # 3. 可以在这里搞事情
        if "warning" in data:
            print(">>> 警告！检测到异常！")