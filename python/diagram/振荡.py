import numpy as np
import matplotlib.pyplot as plt

# --- 1. 设置电路参数 (物理定数) ---
# 假设 E=10V, L=1H, C1=C2=C=1F (为了简化计算和清晰绘图)
E = 10.0   # 初始电压 (V)
L = 1.0    # 电感 (H)
C = 1.0    # 电容 (F) (C1 = C2 = C)

# --- 2. 计算衍生参数 (導出パラメータ) ---
# 等效电容 C_eq
C_eq = (C * C) / (C + C)  # C/2 = 0.5 F

# 角频率 omega (角周波数)
omega = np.sqrt(1 / (L * C_eq))  # sqrt(1 / (1 * 0.5)) = sqrt(2)

# 最大电流 I_max
I_max = E * omega * C_eq  # 10 * sqrt(2) * 0.5 = 5 * sqrt(2)

# 振荡周期 T (周期)
T = 2 * np.pi / omega  # 2 * pi / sqrt(2) = pi * sqrt(2)

# --- 3. 生成时间和波形数据 ---
# 我们来绘制两个完整的周期 (0 から 2T まで)
t = np.linspace(0, 2 * T, 500) # 500个时间点

# 根据我们推导的公式计算电压和电流
v_c1 = (E / 2) * (1 + np.cos(omega * t))
v_c2 = (E / 2) * (1 - np.cos(omega * t))
i_t = I_max * np.sin(omega * t)

# --- 4. 使用 Matplotlib 绘图 ---
# 设置中文显示 (防止Matplotlib中文乱码)
plt.rcParams['font.sans-serif'] = ['SimHei']  # 或者 'Microsoft YaHei'
plt.rcParams['axes.unicode_minus'] = False  # 正常显示负号

# 创建图形和坐标系
fig, ax1 = plt.subplots(figsize=(10, 6))

# 绘制 v_c1 和 v_c2 (使用左侧Y轴 - ax1)
color1 = 'tab:red'
ax1.set_xlabel('时间 t (s)')
ax1.set_ylabel('电压 V (V)', color='black')
ax1.plot(t, v_c1, color=color1, linestyle='-', label='$v_{C1}(t)$ (C1 电压)')
ax1.plot(t, v_c2, color='tab:blue', linestyle='-', label='$v_{C2}(t)$ (C2 电压)')
ax1.tick_params(axis='y', labelcolor='black')
ax1.set_ylim(-0.5, E + 0.5) # 设置Y轴范围

# 创建第二个坐标系 (共享X轴 - ax2) 用于绘制电流
ax2 = ax1.twinx()
color2 = 'tab:green'
ax2.set_ylabel('电流 i (A)', color=color2)
ax2.plot(t, i_t, color=color2, linestyle='--', label='$i(t)$ (环路电流)')
ax2.tick_params(axis='y', labelcolor=color2)

# --- 5. 添加图例、标题和网格 ---
# 合并两个坐标系的图例
lines1, labels1 = ax1.get_legend_handles_labels()
lines2, labels2 = ax2.get_legend_handles_labels()
ax1.legend(lines1 + lines2, labels1 + labels2, loc='upper right')

plt.title(f'C1=C2 时的LC串联振荡 (E={E}V, L={L}H, C={C}F)')
ax1.grid(True) # 显示网格
fig.tight_layout() # 调整布局防止标签重叠

# 显示图像
plt.show()