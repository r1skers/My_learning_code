from pathlib import Path
import shutil

def organize_logs_by_date(source_dir_path):
    # 在这里编写你的代码   
    print(f"源文件夹路径: {source_dir_path}")
    print('准备开始遍历文件...')
    for file_path in source_dir_path.iterdir():
        if file_path.is_file() and file_path.suffix == '.log':
            print(f"找到日志文件: {file_path.name}")
            # 提取日期信息
            file_time=file_path.stem[0:10] 
            print(f"提取的日期: {file_time}") 
            # 创建目标文件夹路径  
            dest_folder_path = source_dir_path / file_time
            dest_folder_path.mkdir(exist_ok=True)
            # 移动文件
            new_path = dest_folder_path / file_path.name
            file_path.rename(new_path)
            print(f"移动文件: '{file_path}' -> 到 '{file_time}' 文件夹")
    print("整理完成！")
pass


organize_logs_by_date(Path(r'D:\Github_Repos\My_learning_code\python\organize_logs_by_date\log'))




