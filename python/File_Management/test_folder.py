from pathlib import Path  # 导入 Path 对象
import shutil

# Windows 示例:
target_folder_path = Path(r'D:\Github_Repos\My_learning_code\python\File_Management\test_folder') 


try:
    print(f"--- 开始整理 '{target_folder_path}' ---")

    # Path.iterdir() 会返回一个包含所有路径对象的迭代器
    for item_path in target_folder_path.iterdir():
        
        # 判断是否为文件
        if item_path.is_file():
            
            # 只处理有扩展名的文件 (.suffix 会返回扩展名字符串)
            if item_path.suffix:
                
                # 1. 根据扩展名创建目标文件夹的路径
                dest_folder_name = item_path.suffix[1:]
                dest_folder_path = target_folder_path / dest_folder_name
                
                # 2. 检查并创建文件夹
                dest_folder_path.mkdir(exist_ok=True) # mkdir更简单，exist_ok=True表示如果存在就不报错
                
                # 3. 移动文件
                new_path = dest_folder_path / item_path.name
                item_path.rename(new_path)
                print(f"移动文件: '{item_path.name}' -> 到 '{dest_folder_name}' 文件夹")

    print("--- 整理完成！ ---")

except FileNotFoundError:
    print(f"错误：找不到文件夹 '{target_folder_path}'。请确认路径是否正确。")