''' 
项目二：重复文件扫描器 (Duplicate File Scanner)
项目描述：扫描指定文件夹及其所有子文件夹，找出内容完全相同的文件（例如，多次下载的同一个文件）。

实现思路：

第一轮筛选（按大小）：遍历所有文件，记录下每个文件的大小。如果两个文件大小不同，它们的内容一定不同。您可以创建一个字典，key是文件大小，value是拥有该大小的文件路径列表。

第二轮确认（按内容哈希）：对于那些大小相同的文件组，逐一读取文件内容，并计算其哈希值（比如MD5或SHA256）。哈希值是文件的“数字指纹”，如果哈希值相同，就可以99.99%确定文件内容完全相同。

您将接触到的新知识：

递归遍历子文件夹（使用 Path.glob('**/*')）。

读取文件的二进制内容（open 函数的 'rb' 模式）。

使用 hashlib 模块来计算文件的哈希值。
'''




import os
from pathlib import Path
import hashlib

script_dir=Path(__file__).parent
size_dict={}
hash_dict={}
try:
    for path in script_dir.iterdir():
        if not path.is_file() and path.name!=Path(__file__).name:
            continue
    
        size=path.stat().st_size
        if size in size_dict:
            size_dict[size].append(path)
        else:
            size_dict[size]=[path]

            
        duplicates_found = False
    for files_list in size_dict.items():
        if len(files_list)>1:
            duplicates_found = True
            print(f"\n[!] 发现一组大小相同的文件 (大小: {size} 字节):")
        for path in files_list:
                print(f"  -> {path}")
        for file in files_list:
                with open(file,'rb') as f:
                    file_hash=hashlib.md5(f.read()).hexdigest()
                if file_hash in hash_dict:
                    hash_dict[file_hash].append(file)
                else:
                    hash_dict[file_hash]=[file]
        for dup_files in hash_dict.values():
            if len(dup_files)>1:
                print(f"\n[!!!] 发现重复文件 (哈希: {file_hash}):")
                for dup in dup_files:
                    print(f"  --> {dup}")
    if not duplicates_found:
        print("未发现重复文件。")
except FileNotFoundError:
    print("错误: 指定的文件或目录不存在。")





'''改进后的代码：递归扫描子目录并优化输出'''
'''
from pathlib import Path
import hashlib

def find_duplicate_files(root_dir: Path):
    """
    扫描指定目录及其子目录，找出重复的文件。
    """
    # === 第一阶段：按文件大小筛选 ===
    print("第一阶段：按文件大小筛选中...")
    size_dict = {}
    # 使用 .glob('**/*') 来递归遍历所有子目录和文件
    for path in root_dir.glob('**/*'):
        # 跳过目录和脚本自身
        if not path.is_file() or path.name == Path(__file__).name:
            continue
        
        try:
            size = path.stat().st_size
            # 跳过空文件
            if size == 0:
                continue
            
            if size in size_dict:
                size_dict[size].append(path)
            else:
                size_dict[size] = [path]
        except FileNotFoundError:
            # 文件在遍历过程中可能被删除，跳过即可
            continue

    # === 第二阶段：对潜在重复文件按哈希值确认 ===
    print("\n第二阶段：对大小相同的组进行哈希值确认...")
    # 只处理文件数量 > 1 的组
    duplicates_found = False
    
    for size, files in size_dict.items():
        if len(files) < 2:
            continue
            
        print(f"\n[!] 正在检查大小为 {size} 字节的 {len(files)} 个文件...")
        hash_dict = {} # 对每一组大小相同的文件，用一个新的hash_dict
        for file_path in files:
            try:
                with open(file_path, 'rb') as f:
                    file_hash = hashlib.md5(f.read()).hexdigest()

                if file_hash in hash_dict:
                    hash_dict[file_hash].append(file_path)
                else:
                    hash_dict[file_hash] = [file_path]
            except IOError as e:
                print(f"  -> 读取文件 {file_path.name} 失败: {e}")
        
        # === 第三阶段：打印本组的哈希结果 ===
        for file_hash, paths in hash_dict.items():
            if len(paths) > 1:
                duplicates_found = True
                print(f"  [!!!] 发现内容重复的文件 (哈希: {file_hash})")
                for path in paths:
                    print(f"    --> {path}")
'''                    

    