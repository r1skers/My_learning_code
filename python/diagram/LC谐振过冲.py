import numpy as np
import matplotlib.pyplot as plt

# --- 1. 设置电路参数 (物理定数) ---
# 假设 E=10V, L=1H, C1=100F, C2=1F (突出 C1 >> C2)
E = 10.0   # 初始电压 (V)
L = 1.0    # 电感 (H)
C1 = 100.0 # 大电容 C1 (F)
C2 = 1.0   # 小电容 C2 (F)

# --- 2. 计算衍生参数 (導出パラメータ) ---
# 等效电容 C_eq
C_eq = (C1 * C2) / (C1 + C2)  # 100 * 1 / (100 + 1) = 100 / 101 ~= 0.99 F (近似于 C2)

# 角频率 omega (角周波数)
omega = np.sqrt(1 / (L * C_eq)) # sqrt(1 / (1 * 100/101)) = sqrt(101/100) ~= 1.005 rad/s

# 实际最大电流 I_max (非近似值)
I_max = E * omega * C_eq

# 振荡周期 T (周期)
T = 2 * np.pi / omega

# --- 3. 生成时间和波形数据 ---
# 绘制两个完整的周期
t = np.linspace(0, 2 * T, 500) # 500个时间点

# 根据我们之前推导的精确公式计算电压和电流
# V_C1_factor = E / (C1 + C2)
# V_C2_factor = E * C1 / (C1 + C2)
# v_c1 = V_C1_factor * (C1 + C2 * np.cos(omega * t))
# v_c2 = V_C2_factor * (1 - np.cos(omega * t))
# i_t = I_max * np.sin(omega * t)

# 为了更清晰地看到近似效果，我们这次也绘制近似曲线
# 精确公式
v_c1_exact = (E / (C1 + C2)) * (C1 + C2 * np.cos(omega * t))
v_c2_exact = (E * C1 / (C1 + C2)) * (1 - np.cos(omega * t))
i_t_exact = I_max * np.sin(omega * t)

# 近似公式 (C1 >> C2)
# 注意：近似公式中的omega是sqrt(1/(L*C2))
omega_approx = np.sqrt(1 / (L * C2))
I_max_approx = E * np.sqrt(C2 / L)
v_c1_approx = E + (E * C2 / C1) * np.cos(omega_approx * t) # 更精细的近似
v_c2_approx = E * (1 - np.cos(omega_approx * t))
i_t_approx = I_max_approx * np.sin(omega_approx * t)


# --- 4. 使用 Matplotlib 绘图 ---
# 设置中文显示 (防止Matplotlib中文乱码)
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 10), sharex=True)

# --- 子图1: 电压 ---
ax1.set_ylabel('电压 V (V)', color='black')
# 精确曲线
ax1.plot(t, v_c1_exact, color='tab:red', linestyle='-', label='$v_{C1}(t)$ (C1 电压 - 精确)')
ax1.plot(t, v_c2_exact, color='tab:blue', linestyle='-', label='$v_{C2}(t)$ (C2 电压 - 精确)')
# 近似曲线
ax1.plot(t, v_c1_approx, color='darkred', linestyle='--', label='$v_{C1}(t)$ (C1 电压 - 近似 $E$ )')
ax1.plot(t, v_c2_approx, color='darkblue', linestyle='--', label='$v_{C2}(t)$ (C2 电压 - 近似 $E(1-\cos(\omega t))$)')

ax1.tick_params(axis='y', labelcolor='black')
ax1.set_ylim(-0.5, 2 * E + 0.5) # 设置Y轴范围以容纳2E的过冲
ax1.axhline(y=E, color='gray', linestyle=':', label='初始电压 E') # 初始电压E的参考线
ax1.axhline(y=2*E, color='purple', linestyle=':', label='C2峰值电压 2E') # C2峰值电压2E的参考线
ax1.legend(loc='upper right')
ax1.set_title(f'C1>>C2 时的LC串联振荡 (E={E}V, L={L}H, C1={C1}F, C2={C2}F) - 电压')
ax1.grid(True)

# --- 子图2: 电流 ---
ax2.set_xlabel('时间 t (s)')
ax2.set_ylabel('电流 i (A)', color='tab:green')
# 精确曲线
ax2.plot(t, i_t_exact, color='tab:green', linestyle='-', label='$i(t)$ (环路电流 - 精确)')
# 近似曲线
ax2.plot(t, i_t_approx, color='darkgreen', linestyle='--', label='$i(t)$ (环路电流 - 近似)')

ax2.tick_params(axis='y', labelcolor='tab:green')
ax2.legend(loc='upper right')
ax2.set_title('环路电流')
ax2.grid(True)

fig.tight_layout() # 调整布局防止标签重叠
plt.show()