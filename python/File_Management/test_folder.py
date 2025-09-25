import os
import shutil # 别忘了导入这个新模块！

# 步骤 4: 创建文件夹并移动文件

# (路径保持不变，指向桌面上的 Test_Folder)
# Windows 示例:
target_folder = r'D:\Github_Repos\My_learning_code\python\File_Management' 
# macOS / Linux 示例:
# target_folder = '/Users\YourName\Desktop\Test_Folder'


try:
    all_items = os.listdir(target_folder)
    print(f"--- 开始整理 '{target_folder}' ---")

    for item_name in all_items:
        # 依然是先构造完整路径
        full_path = os.path.join(target_folder, item_name)
        
        # 判断是否为文件
        if os.path.isfile(full_path):
            # 获取扩展名
            file_root, file_extension = os.path.splitext(item_name)
            
            # 只处理有扩展名的文件
            if file_extension:
                # --- 这是本次新增的核心逻辑 ---

                # 1. 根据扩展名创建目标文件夹的路径
                # 我们去掉扩展名前面的'.'，例如 '.txt' -> 'txt'
                dest_folder_name = file_extension[1:]
                dest_folder_path = os.path.join(target_folder, dest_folder_name)
                
                # 2. 检查目标文件夹是否存在，如果不存在，就创建它
                if not os.path.exists(dest_folder_path):
                    os.makedirs(dest_folder_path)
                    print(f"创建新文件夹: '{dest_folder_name}'")
                
                # 3. 移动文件到目标文件夹
                shutil.move(full_path, dest_folder_path)
                print(f"移动文件: '{item_name}' -> 到 '{dest_folder_name}' 文件夹")

    print("--- 整理完成！ ---")

except FileNotFoundError:
    print(f"错误：找不到文件夹 '{target_folder}'。请确认路径是否正确。")