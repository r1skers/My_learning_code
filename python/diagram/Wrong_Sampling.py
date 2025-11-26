import numpy as np
import matplotlib.pyplot as plt

# --- 1. 定义原始信号 (同上) ---
f_max = 15  # 信号最高频率 (Hz)
f_low = 2   # 信号低频 (Hz)
T = 2       # 模拟总时长 (秒)
t_continuous = np.linspace(0, T, 2000)
signal_continuous = np.sin(2 * np.pi * f_low * t_continuous) + \
                    np.sin(2 * np.pi * f_max * t_continuous)

# --- 2. 场景二：错误采样 (Aliasing) ---
fs_bad = 20  # 采样率 (Hz)。(!!! 严重小于 2 * 15 = 30 Hz !!!)
# 离散的采样时间点
t_sampled_bad = np.arange(0, T, 1/fs_bad)
# 离散的采样值
signal_sampled_bad = np.sin(2 * np.pi * f_low * t_sampled_bad) + \
                     np.sin(2 * np.pi * f_max * t_sampled_bad)

# --- 3. 绘图 ---
plt.figure(figsize=(15, 10))

# 图 1: 信号 vs 采样点
plt.subplot(2, 1, 1)
plt.plot(t_continuous, signal_continuous, label=f"Original Signal (f={f_low}Hz & {f_max}Hz)", alpha=0.6)
plt.stem(t_sampled_bad, signal_sampled_bad, 'r',
         markerfmt='ro', basefmt=' ', linefmt='r-',
         label=f"Bad Sampling (fs = {fs_bad} Hz)")
plt.title("Scene 2: Bad Sampling (fs < 2 * f_max) -> ALIASING!")
plt.xlabel("Time (t)")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)

# 图 2: FFT 结果 (光谱)
# 计算 FFT
N_bad = len(t_sampled_bad)
fft_freq_bad = np.fft.fftfreq(N_bad, 1/fs_bad)
fft_val_bad = np.abs(np.fft.fft(signal_sampled_bad)) / N_bad

# 只看正频率部分
fft_freq_bad = fft_freq_bad[0:N_bad//2]
fft_val_bad = fft_val_bad[0:N_bad//2] * 2 # 恢复幅度

plt.subplot(2, 1, 2)
plt.stem(fft_freq_bad, fft_val_bad)
plt.title("FFT Result (Spectrum) - !! WRONG !!")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Intensity")
plt.vlines(f_low, 0, 1, colors='g', linestyles='dashed', label=f"Original {f_low}Hz (Correct)")
# 混叠的频率: f_aliased = |f_max - fs_bad| = |15 - 20| = 5 Hz
f_aliased = abs(f_max - fs_bad)
plt.vlines(f_aliased, 0, 1, colors='red', linestyles='dashed', label=f"!! Aliased 'Fake' Freq. ({f_aliased} Hz) !!")
plt.xlim(0, fs_bad/2) # 只显示到奈奎斯特频率 (10 Hz)
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()