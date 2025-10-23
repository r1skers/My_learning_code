import numpy as np
import matplotlib.pyplot as plt

# --- 1. 定义电路参数 ---
E = 100.0        # 电源 (V)
R1 = 100.0       # 电阻 R1 (Ω)
R2 = 900.0       # 电阻 R2 (Ω)
C = 1e-6         # 电容 (F) (1微法 = 1 * 10^-6)
t_switch = 0.001   # 开关切换时间 (s)

# --- 2. 阶段一 (0 <= t < t_switch) 的计算 ---
# 电路: E, R1, C, R2 串联
tau1 = (R1 + R2) * C   # 阶段一的时间常数 (1000 * 1e-6 = 0.001 s)
I_initial1 = E / (R1 + R2) # 阶段一的 t=0+ 初始电流 (100 / 1000 = 0.1 A)
I_final1 = 0.0           # 阶段一的 t=inf 最终电流 (电容开路)

# --- 3. 切换瞬间 (t = 0.001s) ---
# S2 闭合前的瞬间，V_C 是多少?
V_C_switch = E * (1 - np.exp(-t_switch / tau1))
# V_C_switch ≈ 100 * (1 - e^-1) ≈ 63.212 V

# S2 闭合前的瞬间，电流 I 是多少?
I_switch_before = I_initial1 * np.exp(-t_switch / tau1)
# I_switch_before ≈ 0.1 * e^-1 ≈ 0.0368 A

# S2 闭合后的瞬间，电流 I 是多少? (发生跃变)
# 新回路 E-R1-C, V_C 保持 63.212V
I_switch_after = (E - V_C_switch) / R1
# I_switch_after ≈ (100 - 63.212) / 100 ≈ 0.3679 A (峰值电流)

# --- 4. 阶段二 (t >= t_switch) 的计算 ---
# 电路: E, R1, C 串联 (R2被S2短路)
tau2 = R1 * C            # 阶段二的时间常数 (100 * 1e-6 = 0.0001 s)
I_final2 = 0.0           # 阶段二的 t=inf 最终电流 (电容开路)

# --- 5. 生成时间和电流数据 ---
# 生成一个从 0 到 2ms 的时间数组
t_end = 0.002
t = np.linspace(0, t_end, 2000) # 增加点数以捕捉快速衰减

# 创建一个全零的数组来存放电流值
i = np.zeros_like(t)

# 使用布尔掩码 (boolean masks)
mask1 = (t >= 0) & (t < t_switch)  # 阶段一的时间范围
mask2 = t >= t_switch              # 阶段二的时间范围

# (公式修正) 计算阶段一的电流: I(t) = I(0+) * exp(-t/tau1)
i[mask1] = I_initial1 * np.exp(-t[mask1] / tau1)

# (公式修正) 计算阶段二的电流: I(t) = I(t_sw+) * exp(-(t-t_sw)/tau2)
i[mask2] = I_switch_after * np.exp(-(t[mask2] - t_switch) / tau2)

# --- 6. 使用 Matplotlib 绘图 ---
plt.figure(figsize=(10, 6))

# 绘制电流曲线
plt.plot(t, i, label='$I(t)$', color='blue', linewidth=2)

# 标记开关切换的时刻
plt.axvline(x=t_switch, color='red', linestyle='--', label=f'S2 闭合 (t = {t_switch*1000} ms)')

# 标记跃变点 (之前)
plt.scatter([t_switch], [I_switch_before], color='blue', zorder=5, facecolors='none')
plt.annotate(f'$I(1\mathrm{{ms}}^-) \approx {I_switch_before:.3f}$ A',
             xy=(t_switch, I_switch_before),
             xytext=(t_switch - 0.0007, I_switch_before + 0.05))

# 标记跃变点 (之后)
plt.scatter([t_switch], [I_switch_after], color='red', zorder=5)
plt.annotate(f'$I(1\mathrm{{ms}}^+) \approx {I_switch_after:.3f}$ A',
             xy=(t_switch, I_switch_after),
             xytext=(t_switch + 0.0001, I_switch_after * 0.9))

# --- 7. 设置图表样式 (标签修正) ---
plt.xlabel('时间 $t$ (seconds)')
plt.ylabel('环路电流 $I$ (Amperes)')
plt.title('RC 电路分段过渡过程 ($I$ 随时间的变化)')
plt.grid(True)
plt.legend()
plt.xlim(0, t_end)
# 设置 y 轴范围 (基于峰值电流 I_switch_after)
plt.ylim(0, I_switch_after * 1.1) 

# 显示图像
plt.show()