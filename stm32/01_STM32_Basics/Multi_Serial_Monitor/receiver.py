import serial
import threading
import time

# --- 配置区域 ---
PORT_A = 'COM6'  # 对应你的 UART1 (DAPLink)
PORT_B = 'COM3'  # 对应你的 UART2 (USB-TTL)
BAUD_RATE = 115200

# 全局标志位，控制线程退出
running = True

# --- 接收线程函数 ---
def read_from_port(ser, port_name):
    print(f"✅ 监听线程启动: {port_name}")
    while running:
        try:
            if ser.in_waiting > 0:
                # 读取数据并解码
                data = ser.read(ser.in_waiting)
                text = data.decode('utf-8', errors='ignore').strip()
                if text:
                    print(f"\n[收到 @ {port_name}] 长度:{len(data)} | 内容: {text}")
                    print("-" * 40)
            time.sleep(0.01) # 稍微休息，降低CPU占用
        except Exception as e:
            print(f"❌ {port_name} 读取出错: {e}")
            break

# --- 主程序 ---
if __name__ == "__main__":
    print("--- STM32 多串口双向转发测试 ---")

    try:
        # 1. 打开两个串口
        # timeout=1 表示读取时的超时时间，这里主要用于防止阻塞
        ser_a = serial.Serial(PORT_A, BAUD_RATE, timeout=1)
        ser_b = serial.Serial(PORT_B, BAUD_RATE, timeout=1)

        # 2. 启动两个接收线程 (就像雇了两个保安分别盯着两个门)
        thread_a = threading.Thread(target=read_from_port, args=(ser_a, PORT_A))
        thread_b = threading.Thread(target=read_from_port, args=(ser_b, PORT_B))

        thread_a.daemon = True # 设置为守护线程，主程序关掉时它们自动关掉
        thread_b.daemon = True

        thread_a.start()
        thread_b.start()

        time.sleep(1) # 等待线程就绪

        # 3. 开始自动发送测试
        while True:
            # --- 测试 A -> B ---
            msg_to_send = f"Hello from {PORT_A} (Time: {time.time():.2f})"
            print(f"📤 [发送] {PORT_A} >>> 你好呀 >>> {PORT_B}")
            ser_a.write(msg_to_send.encode('utf-8'))

            time.sleep(1.5) # 间隔一下

            # --- 测试 B -> A ---
            msg_to_send = f"Greetings from {PORT_B} (Time: {time.time():.2f})"
            print(f"📤 [发送] {PORT_B} >>> 我不好 >>> {PORT_A}")
            ser_b.write(msg_to_send.encode('utf-8'))

            time.sleep(1.5)

    except serial.SerialException as e:
        print(f"\n❌ 串口打开失败! 请检查:\n1. 串口助手(SSCOM/XCOM)是不是没关？\n2. 端口号写对了吗？\n错误详情: {e}")
    except KeyboardInterrupt:
        print("\n🛑 测试停止")
    finally:
        running = False
        # 关闭串口资源
        if 'ser_a' in locals() and ser_a.is_open: ser_a.close()
        if 'ser_b' in locals() and ser_b.is_open: ser_b.close()
        print("👋 Bye!")