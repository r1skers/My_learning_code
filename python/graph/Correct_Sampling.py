import numpy as np
import matplotlib.pyplot as plt

# --- 1. 定义原始信号 ---
f_max = 15  # 信号最高频率 (Hz)
f_low = 2   # 信号低频 (Hz)
T = 2       # 模拟总时长 (秒)

# "连续"信号 (用非常高的采样率模拟)
t_continuous = np.linspace(0, T, 2000)
signal_continuous = np.sin(2 * np.pi * f_low * t_continuous) + \
                    np.sin(2 * np.pi * f_max * t_continuous)

# --- 2. 场景一：正确采样 ---
fs_good = 100  # 采样率 (Hz)。这大于 2 * 15 = 30 Hz
# 离散的采样时间点
t_sampled_good = np.arange(0, T, 1/fs_good)
# 离散的采样值
signal_sampled_good = np.sin(2 * np.pi * f_low * t_sampled_good) + \
                      np.sin(2 * np.pi * f_max * t_sampled_good)

# --- 3. 绘图 ---
plt.figure(figsize=(15, 10))

# 图 1: 信号 vs 采样点
plt.subplot(2, 1, 1)
plt.plot(t_continuous, signal_continuous, label=f"Original Signal (f={f_low}Hz & {f_max}Hz)", alpha=0.6)
plt.stem(t_sampled_good, signal_sampled_good, 'r',
         markerfmt='ro', basefmt=' ', linefmt='r-',
         label=f"Good Sampling (fs = {fs_good} Hz)")
plt.title("Scene 1: Correct Sampling (fs > 2 * f_max)")
plt.xlabel("Time (t)")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)

# 图 2: FFT 结果 (光谱)
# 计算 FFT
N_good = len(t_sampled_good)
fft_freq_good = np.fft.fftfreq(N_good, 1/fs_good)
fft_val_good = np.abs(np.fft.fft(signal_sampled_good)) / N_good

# 只看正频率部分
fft_freq_good = fft_freq_good[0:N_good//2]
fft_val_good = fft_val_good[0:N_good//2] * 2  # 恢复幅度

plt.subplot(2, 1, 2)
plt.stem(fft_freq_good, fft_val_good)
plt.title("FFT Result (Spectrum) - Correct")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Intensity")
plt.vlines([f_low, f_max], 0, 1, colors='g', linestyles='dashed', label=f"Original Frequencies ({f_low}Hz, {f_max}Hz)")
plt.xlim(0, fs_good/2) # 只显示到奈奎斯特频率
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()