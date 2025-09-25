import os

# __file__ 是一个特殊的Python变量，它代表当前这个脚本文件本身的路径
# 比如 'd:/.../File Management/script.py'

# 1. 获取脚本文件自己的绝对路径
# os.path.abspath() 确保我们得到一个完整的、没有歧义的路径
script_path = os.path.abspath(__file__)

# 2. 从脚本的完整路径中，只获取它所在的文件夹的路径
# os.path.dirname() 就是用来做这个的
script_directory = os.path.dirname(script_path)

# 3. 使用 os.path.join() 将文件夹路径和我们想要的文件名安全地拼接起来
# 这会生成一个指向正确位置的完整文件路径
file_path_to_create = os.path.join(script_directory, 'hello.txt')

print(f"脚本所在的文件夹是: {script_directory}")
print(f"将在以下完整路径创建文件: {file_path_to_create}")


# 使用这个计算出的完整路径来打开和写入文件
with open(file_path_to_create, 'w', encoding='utf-8') as f:
    f.write('你好，Python！我现在在正确的位置了。\n')
    f.write('这是新的一行。\n')

print("文件写入成功！")

# 这样，无论这个脚本被放在哪里运行，它总是会在它自己的文件夹里创建 'hello.txt' 文件






print(f"当前目录是: {os.getcwd()}")
print("-" * 20)
print("上级目录的所有内容如下：")

try:
    # '..' 代表父目录
    parent_dir_contents = os.listdir('..')
    
    for item in parent_dir_contents:
        print(item)

except FileNotFoundError:
    print("找不到父目录，可能当前已经在根目录了。")