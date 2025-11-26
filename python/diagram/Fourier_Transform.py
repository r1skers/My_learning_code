import numpy as np
import matplotlib.pyplot as plt

# 设置 Matplotlib 支持中文显示
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

# --- 1. 定义信号参数 ---
W = 1.0  # 脉冲宽度 (保持不变)
T1 = 2.0  # 周期 T (情况1：短周期)
T2 = 8.0  # 周期 T (情况2：长周期)

w0_1 = 2 * np.pi / T1  # T1 对应的基波角频率
w0_2 = 2 * np.pi / T2  # T2 对应的基波角频率

# --- 2. 定义辅助函数 ---

# (a) 创建时域的周期性脉冲串
def create_pulse_train(t, T, W):
    """创建一个周期为T，脉宽为W的脉冲串"""
    # 使用模运算来创建周期信号
    # (t + T/2) % T - T/2 会将t映射到 [-T/2, T/2] 范围
    t_periodic = (t + T/2) % T - T/2
    return np.where(np.abs(t_periodic) < W/2, 1.0, 0.0)

# (b) 计算傅里叶级数 c_n
def get_fourier_series(n_max, T, W):
    """计算傅里叶级数 c_n"""
    # c_n = (W/T) * sinc(n * W / T)
    # np.sinc(x) = sin(pi*x) / (pi*x)
    n = np.arange(-n_max, n_max + 1)
    
    # 基波角频率
    w0 = 2 * np.pi / T
    
    # 离散的频率点
    omega_n = n * w0
    
    # 计算 c_n
    c_n = (W / T) * np.sinc(n * W / T)
    
    # 处理 n=0 (即 w=0) 的特殊情况
    # c_0 = (1/T) * 积分(-W/2, W/2) dt = W/T
    # np.sinc(0) = 1，所以公式已经正确处理了
    
    return omega_n, c_n

# (c) 计算傅里叶变换 F(w) (即 T -> inf 的包络)
def get_fourier_transform(w, W):
    """计算单个脉冲的傅里叶变换 F(w)"""
    # F(w) = W * sinc(w * W / (2*pi))
    return W * np.sinc(w * W / (2 * np.pi))

# --- 3. 创建绘图 ---
fig, axes = plt.subplots(3, 2, figsize=(12, 15))
fig.suptitle("从傅里叶级数 (FS) 到 傅里叶变换 (FT) 的演化", fontsize=16)

# 时间轴和频率轴范围
t_range = np.linspace(-12, 12, 2000)
w_range = np.linspace(-25, 25, 1000)

# --- 图 1: 短周期 T1 ---
ax_t1 = axes[0, 0]
ax_f1 = axes[0, 1]

# 时域
f_t1 = create_pulse_train(t_range, T1, W)
ax_t1.plot(t_range, f_t1, 'b')
ax_t1.set_title(f"情况 1: 时域 (周期 T = {T1})")
ax_t1.set_xlabel("时间 t")
ax_t1.set_ylabel("f(t)")
ax_t1.grid(True)

# 频域 (傅里叶级数)
w_n1, c_n1 = get_fourier_series(n_max=10, T=T1, W=W)
ax_f1.stem(w_n1, c_n1, 'b', markerfmt='bo', basefmt=' ')
ax_f1.set_title(f"频域 (傅里叶级数 $c_n$) - 谱线间隔 $\omega_0 = {w0_1:.2f}$")
ax_f1.set_xlabel("角频率 $\omega$")
ax_f1.set_ylabel("$c_n$ (幅度)")
ax_f1.grid(True)

# --- 图 2: 长周期 T2 ---
ax_t2 = axes[1, 0]
ax_f2 = axes[1, 1]

# 时域
f_t2 = create_pulse_train(t_range, T2, W)
ax_t2.plot(t_range, f_t2, 'g')
ax_t2.set_title(f"情况 2: 时域 (周期 T = {T2})")
ax_t2.set_xlabel("时间 t")
ax_t2.set_ylabel("f(t)")
ax_t2.grid(True)

# 频域 (傅里叶级数)
w_n2, c_n2 = get_fourier_series(n_max=40, T=T2, W=W) # n_max需要更大才能覆盖相同频率范围
ax_f2.stem(w_n2, c_n2, 'g', markerfmt='go', basefmt=' ')
ax_f2.set_title(f"频域 (傅里叶级数 $c_n$) - 谱线间隔 $\omega_0 = {w0_2:.2f}$")
ax_f2.set_xlabel("角频率 $\omega$")
ax_f2.set_ylabel("$c_n$ (幅度)")
ax_f2.grid(True)

# --- 图 3: T -> 无穷大 (极限) ---
ax_t3 = axes[2, 0]
ax_f3 = axes[2, 1]

# 时域 (单个脉冲)
f_t_inf = create_pulse_train(t_range, T=1000, W=W) # 用一个非常大的T来模拟
ax_t3.plot(t_range, f_t_inf, 'r')
ax_t3.set_title(r"情况 3: 时域 ($T \to \infty$ 的极限)")
ax_t3.set_xlabel("时间 t")
ax_t3.set_ylabel("f(t)")
ax_t3.set_xlim(-12, 12) # 保持x轴范围一致
ax_t3.grid(True)

# 频域 (傅里叶变换)
F_w = get_fourier_transform(w_range, W)
ax_f3.plot(w_range, F_w, 'r')
ax_f3.set_title(r"频域 ($T \to \infty$ 的极限) -> 傅里叶变换 $F(\omega)$")
ax_f3.set_xlabel("角频率 $\omega$")
ax_f3.set_ylabel("$F(\omega)$ (频谱密度)")
ax_f3.grid(True)

# --- 调整布局并显示 ---
plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()