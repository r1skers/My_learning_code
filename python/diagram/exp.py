import numpy as np
import matplotlib.pyplot as plt

# --- 你提供的 ABC 值 ---
A = 5.164
B = -12500
C = 48412
# ----------------------

# --- 关键调整 ---
# 因为 B 和 C 都非常大，我们需要一个非常小的 x 范围 和 更多的点 来观察图像
# 
# 衰减分析：exp(-12500 * x) 在 x=0.001 时 约等于 3.7e-6 (几乎为0)
# 周期分析：sin(48412 * x) 的周期 T = 2*pi / 48412 ≈ 0.00013
#
# 所以我们选择一个能看到几个周期的范围，例如 0 到 0.0005
x_end = 0.0005 
num_points = 2000 # 需要足够多的点来捕捉高速振荡
# ----------------------

x = np.linspace(0, x_end, num_points)

# 计算 y 值 (原始函数)
y = A * np.exp(B * x) * np.sin(C * x)

# --- 计算包络线的值 ---
envelope_positive = A * np.exp(B * x)
envelope_negative = -A * np.exp(B * x)
# ----------------------

# --- 绘图代码 ---
plt.figure(figsize=(12, 7)) # 设置图像大小

# 绘制原始函数曲线
# 使用 f-string 和 LaTeX 语法 (r'$...$') 来自动生成图例
# 为了防止图例过长，我们对 B 和 C 使用科学计数法 (:.2e)
label_str_main = f'$y = {A} \\times e^{{{B:.2e}x}} \\times \\sin({C:.2e}x)$'
plt.plot(x, y, label=label_str_main, color='blue', linewidth=1) # 蓝色细线

# 绘制包络线
# 我们使用红色虚线 ('r--') 来表示包络线
label_str_envelope = f'Envelope: $\\pm {A} \\times e^{{{B:.2e}x}}$'
plt.plot(x, envelope_positive, 'r--', label=label_str_envelope, linewidth=1.5) # 正包络线
plt.plot(x, envelope_negative, 'r--', linewidth=1.5) # 负包络线 (不需要再次添加label，它会共用上面的label)

# 2. 调用 plt.legend() 来显示图例
plt.legend(fontsize='large', loc='upper right') # 'large' 可以让字体更清晰, loc='upper right' 放在右上角

# 添加标题和标签
plt.title('Plot of Damped Sine Wave with Envelopes')
plt.xlabel('$x$')
plt.ylabel('$y$')

# 添加网格
plt.grid(True)
plt.minorticks_on() # 显示次级刻度线
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black') # 主刻度线
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='gray')  # 次刻度线

# 调整 y 轴范围，使其稍微超出包络线，看起来更美观
plt.ylim(min(envelope_negative) * 1.1, max(envelope_positive) * 1.1)


# 保存图像
plt.savefig('my_plot_with_envelopes.png', dpi=300) # dpi=300 提高保存图像的清晰度

# 在本地运行时, 取消下面这行的注释来显示图像
plt.show()