import serial
import struct
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque
import numpy as np
import time

# === 配置区 ===
PORT = 'COM5'      # <--- 确认你的端口号
BAUD = 115200
FRAME_SIZE = 11
WINDOW_SIZE = 200  # 显示窗口大小

# === 数据容器 ===
y_data = deque([0] * WINDOW_SIZE, maxlen=WINDOW_SIZE)

# === 统计变量 ===
packet_count = 0
start_time = time.time()
current_fps = 0.0

# === 连接串口 ===
try:
    ser = serial.Serial(PORT, BAUD, timeout=0.1)
    print(f"成功连接 {PORT}")
except Exception as e:
    print(f"串口错误: {e}")
    exit()

# === 绘图初始化 ===
fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2, color='#00ff00') # 荧光绿
ax.set_facecolor('black') # 示波器风格背景
ax.set_ylim(-100, 4200)
ax.set_xlim(0, WINDOW_SIZE)
ax.grid(True, color='#333333')

# 仪表盘文字
info_text = ax.text(0.02, 0.95, '', transform=ax.transAxes, 
                    color='white', fontsize=12, verticalalignment='top',
                    bbox=dict(boxstyle='round', facecolor='blue', alpha=0.3))

def calculate_fft(signal, fs):
    """ 计算主频率 """
    if len(signal) < WINDOW_SIZE: return 0
    signal_np = np.array(signal)
    
    # FFT 变换
    fft_spectrum = np.fft.rfft(signal_np)
    fft_freqs = np.fft.rfftfreq(len(signal_np), d=1.0/fs)
    
    # 找最大能量对应的频率 (跳过 0Hz 直流分量)
    peak_idx = np.argmax(np.abs(fft_spectrum[1:])) + 1
    return fft_freqs[peak_idx]

def read_serial():
    global packet_count
    # 循环读取直到缓冲区空，防止延迟
    while ser.in_waiting >= FRAME_SIZE:
        if ser.read(1) != b'\xAA': continue
        if ser.read(1) != b'\xAA': continue
        raw = ser.read(FRAME_SIZE - 2)
        if len(raw) < 9: break
        
        try:
            seq, val1, val2, checksum = struct.unpack('<IhhB', raw)
            y_data.append(val1)
            packet_count += 1
        except:
            pass

def update(frame):
    global start_time, packet_count, current_fps
    
    read_serial()
    
    # 计算采样率 (FPS)
    now = time.time()
    dt = now - start_time
    if dt >= 0.5: # 每0.5秒更新一次统计
        current_fps = packet_count / dt
        packet_count = 0
        start_time = now

    # 计算频率 (FFT)
    dominant_freq = 0
    if current_fps > 0 and len(y_data) == WINDOW_SIZE:
        dominant_freq = calculate_fft(y_data, current_fps)

    # 更新图形
    line.set_data(range(len(y_data)), y_data)
    
    # 更新仪表盘
    status_str = (f"Sample Rate: {current_fps:.1f} Hz\n"
                  f"Frequency:   {dominant_freq:.1f} Hz\n"
                  f"Value:       {y_data[-1] if y_data else 0}")
    info_text.set_text(status_str)
    
    return line, info_text

ani = animation.FuncAnimation(fig, update, interval=20, blit=True)
plt.show()
ser.close()