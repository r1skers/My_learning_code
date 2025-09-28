'''
项目一：桌面清理大师 (Desktop Cleanup Master)
项目描述：这是“下载文件夹整理”的升级版。桌面常常是文件混乱的重灾区。这个脚本的目标是自动化整理桌面。

核心功能：

按文件扩展名整理：将 .png, .jpg 等图片文件移动到桌面下的 Images 文件夹；将 .pdf, .docx 移动到 Documents 文件夹等。

按时间归档：扫描桌面上的所有文件，将超过30天没有修改过的文件，统一移动到一个名为 Archive 的文件夹中。

您将接触到的新知识：

如何获取文件的元数据（metadata），特别是最后修改时间（Path.stat().st_mtime）。

使用 datetime 模块来处理和比较时间。
'''
import os
import time
import shutil   
from pathlib import Path

script_path = os.path.abspath(__file__)
script_directory = Path(__file__).parent #Retrieve the directory path of the folder ontaining the script
try:
    for file_path in script_directory.iterdir():
        if file_path.is_() or file_path.name == os.path.basename(__file__):
            continue

        if file_path.suffix: 
            if os.path.getmtime(file_path) < (time.time() - 30*24*60*60): #30 days in seconds
                    archive_folder_path = script_directory / 'Archive'
                    archive_folder_path.mkdir(exist_ok=True)
                    file_path.rename(archive_folder_path / file_path.name) 
                    print(f"移动文件: '{file_path.name}' -> 到 'Archive' 文件夹")
            else:
                if file_path.suffix in ['.pdf', '.docx', '.txt', '.xlsx', '.pptx']:
                        document_folder_path = script_directory / 'Documents'
                        document_folder_path.mkdir(exist_ok=True)
                        file_path.rename(document_folder_path / file_path.name)
                        print(f"移动文件: '{file_path.name}' -> 到 'Documents' 文件夹")
                elif file_path.suffix in ['.png', '.jpg', '.jpeg', '.gif', '.bmp']:
                        image_folder_path = script_directory / 'Images'
                        image_folder_path.mkdir(exist_ok=True)
                        file_path.rename(image_folder_path / file_path.name)
                        print(f"移动文件: '{file_path.name}' -> 到 'Images' 文件夹")
                elif file_path.suffix in ['.mp4', '.mkv', '.avi', '.mov']:
                        video_folder_path = script_directory / 'Videos'
                        video_folder_path.mkdir(exist_ok=True)
                        file_path.rename(video_folder_path / file_path.name)
                        print(f"移动文件: '{file_path.name}' -> 到 'Videos' 文件夹")
    print("--- 整理完成！ ---")
except FileNotFoundError:
    print(f"错误：找不到文件夹 '{script_directory}'。请确认路径是否正确。")









#优化后代码
import time
from pathlib import Path

# 使用 pathlib 获取脚本所在目录
# 这一行就够了，不再需要 os 模块
SOURCE_DIR = Path(__file__).parent
THIRTY_DAYS_AGO = time.time() - 30 * 24 * 60 * 60

# 将整理规则定义在字典中，方便维护
EXTENSIONS_MAP = {
    'Documents': ['.pdf', '.docx', '.txt', '.xlsx', '.pptx'],
    'Images': ['.png', '.jpg', '.jpeg', '.gif', '.bmp'],
    'Videos': ['.mp4', '.mkv', '.avi', '.mov']
}

try:
    for path in SOURCE_DIR.iterdir():
        # 统一过滤掉目录和脚本自身
        if path.is_dir() or path.name == Path(__file__).name:
            continue

        # 如果文件没有扩展名，则跳过
        if not path.suffix:
            continue

        # 优先处理归档逻辑
        if path.stat().st_mtime < THIRTY_DAYS_AGO:
            dest_folder = SOURCE_DIR / 'Archive'
            dest_folder.mkdir(exist_ok=True)
            path.rename(dest_folder / path.name)
            print(f"归档旧文件: '{path.name}' -> 到 'Archive' 文件夹")
            continue # 处理完后继续下一个文件

        # 处理按扩展名分类
        moved = False
        for folder_name, extensions in EXTENSIONS_MAP.items():
            if path.suffix.lower() in extensions:
                dest_folder = SOURCE_DIR / folder_name
                dest_folder.mkdir(exist_ok=True)
                path.rename(dest_folder / path.name)
                print(f"分类文件: '{path.name}' -> 到 '{folder_name}' 文件夹")
                moved = True
                break
        
        # 可选：如果没有任何规则匹配，可以打印一条信息
        # if not moved:
        #     print(f"未分类文件: '{path.name}'")

    print("\n--- 整理完成！ ---")

except FileNotFoundError:
    print(f"错误：找不到文件夹 '{SOURCE_DIR}'。请确认路径是否正确。")
except Exception as e:
    print(f"发生未知错误: {e}")