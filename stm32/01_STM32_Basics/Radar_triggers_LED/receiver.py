import serial

ser = serial.Serial('COM5', 115200, timeout=1)


while True:
    # 1. 这一步会让程序停下来等你打字
    user_input = input("请输入发送内容: ")
    
    # 2. 发送你打的字 (转成字节)
    # 注意：如果 STM32 需要刚好 2 个字节，你最好只输 2 个字母
    ser.write(user_input.encode('utf-8'))
    
    print(f"Python: 已发送 '{user_input}'，等待回传...")
    
    # 3. 稍微睡一下等 STM32 处理
    import time
    time.sleep(0.1)
    
    # 4. 看看 STM32 有没有回话
    if ser.in_waiting:
        data = ser.read_all().decode('utf-8', errors='ignore')
        print(f"STM32 回复: {data}")
    else:
        print("(没收到回复，可能是字节数不够 2 个？)")