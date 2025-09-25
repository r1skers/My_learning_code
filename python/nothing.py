def generate_fibonacci(n):
    if n == 0:
        return []
    elif n == 1:
        return [0]

    fib_list = [0, 1]
    for i in range(n - 2):
        next_number = fib_list[-1] + fib_list[-2]
        fib_list.append(next_number)
    
    return fib_list

data_to_plot = generate_fibonacci(5)
print(f"数列: {data_to_plot}")