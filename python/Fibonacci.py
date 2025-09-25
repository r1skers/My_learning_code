import matplotlib.pyplot as plt

def generate_fibonacci(length):
    """这个函数可以生成一个指定长度的斐波那契数列"""
    if length <= 0:
        return []
    elif length == 1:
        return [0]

    fib_list = [0, 1]
    for i in range(length - 2):
        next_number = fib_list[-1] + fib_list[-2]
        fib_list.append(next_number)
    
    return fib_list

# --- 主程序 ---
# 1. 调用函数生成数据
data_to_plot = generate_fibonacci(20)
print(f"将要绘制的数列: {data_to_plot}")

# 2. 开始绘图
plt.figure(figsize=(10, 6))  # 设置画布大小
plt.plot(data_to_plot, marker='o') # 绘制折线图，并在每个点上加个圆圈标记

# 3. 添加图表标题和坐标轴标签
plt.title("Fibonacci Sequence")
plt.xlabel("Index (位置)")
plt.ylabel("Value (数值)")
plt.grid(True) # 显示网格

# 4. 显示图表
plt.show()