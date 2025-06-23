from sympy import symbols, Eq, solve, pi

x, y = symbols('x y')

eq1 = Eq(200 * pi * x - 1/(200 * pi * y), -10)
eq2 = Eq(400 * pi * x - 1/(400 * pi * y), 20)

# 强制返回字典格式的解
solution = solve((eq1, eq2), (x, y), dict=True)

if solution:
    # 取第一个解（可能有多个解）
    sol_dict = solution[0]
    x_val = sol_dict[x].evalf()
    y_val = sol_dict[y].evalf()
    print(f"x = {x_val:.6f}, y = {y_val:.6f}")
else:
    print("无解")