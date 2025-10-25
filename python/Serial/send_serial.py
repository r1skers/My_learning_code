import serial
import time

# 我们要连接到 com0com 创建的 COM3
port_name = 'COM3'
baud_rate = 9600

print(f"正在尝试连接到 {port_name}...")

try:
    # 1. 初始化并打开串口
    # timeout=1 表示读数据时最多等1秒
    ser = serial.Serial(port_name, baud_rate, timeout=1)
    
    # 检查串口是否真的打开了
    if ser.is_open:
        print(f"成功打开端口: {ser.name}")
    else:
        print(f"未能打开端口: {port_name}")
        exit() # 如果没打开，就退出程序

    # 2. 循环发送数据
    while True:
        # 发送 'ON'
        # b'' 表示这是一个字节字符串 (bytes)，串口通信传输的是原始字节
        ser.write(b'ON') 
        print(f"已发送 -> ON")
        
        # 等待2秒
        time.sleep(2)

        # 发送 'OFF'
        ser.write(b'OFF')
        print(f"已发送 -> OFF")
        
        # 再等待2秒
        time.sleep(2)

except serial.SerialException as e:
    # 捕获串口相关的错误
    print(f"!!! 发生错误: {e}")
    print(f"请检查：")
    print(f"1. com0com 是否已正确设置为 COM3 <-> COM4？")
    print(f"2. 是否有其他程序 (比如PuTTY) 占用了 {port_name}？")

except KeyboardInterrupt:
    # 允许用户按 Ctrl+C 来停止脚本
    print("\n检测到 Ctrl+C，正在停止程序...")

finally:
    # 3. 无论程序是正常结束还是出错，都要关闭串口
    # 检查 'ser' 变量是否存在并且是否处于打开状态
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print(f"已关闭端口: {ser.name}")
    else:
        print("程序结束。")