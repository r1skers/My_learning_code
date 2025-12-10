import os
import re
import shutil
from pathlib import Path

# ================= 配置区域 =================
# 你的文章目录 (请根据实际情况修改，比如 content/posts 或 content/blog)
POSTS_DIR = Path("content/posts") 

# 你的静态资源根目录 (通常是 static)
STATIC_DIR = Path("static")

# 正则匹配 Markdown 图片语法: ![alt](url)
# 捕获组 1: alt 文本, 捕获组 2: 图片路径
IMG_PATTERN = re.compile(r'!\[(.*?)\]\((.*?)\)')
# ===========================================

def migrate_post(md_file: Path):
    """
    将单个 Markdown 文件转换为 Page Bundle 格式
    """
    # 排除已经是 index.md 的文件 (已经是 Bundle 了)
    if md_file.name in ['index.md', '_index.md']:
        return

    print(f"🔨 正在锻造: {md_file.name} ...")

    # 1. 创建同名文件夹
    # 例如: my-post.md -> my-post/
    bundle_dir = md_file.parent / md_file.stem
    if not bundle_dir.exists():
        bundle_dir.mkdir()
    
    # 2. 读取文章内容
    with open(md_file, 'r', encoding='utf-8') as f:
        content = f.read()

    # 3. 查找所有图片链接并处理
    def replace_image(match):
        alt_text = match.group(1)
        img_path_str = match.group(2)
        
        # 忽略网络图片 (http开头)
        if img_path_str.startswith('http'):
            return match.group(0)

        # 尝试定位原本的图片文件
        # 假设链接是 /images/pic.png -> 对应文件 static/images/pic.png
        # 移除开头的 / (如果存在)
        clean_path = img_path_str.lstrip('/')
        original_img_file = STATIC_DIR / clean_path

        # 如果找不到图片，尝试宽松搜索 (处理相对路径等情况)
        if not original_img_file.exists():
            print(f"  ⚠️ 警告: 找不到图片源文件 {img_path_str}，跳过移动。")
            return match.group(0)

        # 4. 移动图片到新的 Bundle 文件夹
        img_filename = original_img_file.name
        target_img_file = bundle_dir / img_filename
        
        # 为了防止文件名冲突，如果目标已存在，就不移动了(或重命名逻辑，这里简化处理)
        if not target_img_file.exists():
            shutil.move(str(original_img_file), str(target_img_file))
            print(f"  ✅ 移动图片: {img_filename}")
        else:
            print(f"  ℹ️ 图片已在目标位置: {img_filename}")

        # 5. 返回新的 Markdown 链接 (直接引用同级文件名)
        return f'![{alt_text}]({img_filename})'

    # 执行正则替换
    new_content = IMG_PATTERN.sub(replace_image, content)

    # 6. 将新内容写入 index.md
    new_index_file = bundle_dir / 'index.md'
    with open(new_index_file, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    # 7. 删除旧的 .md 文件
    os.remove(md_file)
    print(f"✨ 完成转换: {bundle_dir}")

def main():
    if not POSTS_DIR.exists():
        print(f"❌ 错误: 找不到目录 {POSTS_DIR}")
        return

    print("🔥 赫菲斯托斯工坊 - 自动化迁移程序启动 🔥")
    print("==========================================")

    # 遍历所有 .md 文件
    count = 0
    for md_file in POSTS_DIR.glob("*.md"):
        migrate_post(md_file)
        count += 1

    print("==========================================")
    print(f"🎉 全部完成！共处理了 {count} 篇文章。")
    print("⚠️ 注意: 空的 static/images 文件夹可能需要你手动清理。")

if __name__ == "__main__":
    main()