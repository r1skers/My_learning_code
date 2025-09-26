'''
项目三：模板项目生成器 (Template Project Generator)
项目描述：作为一名开发者，每次开始一个新项目时，可能都需要创建一套标准的文件夹结构。例如，一个C语言项目可能需要 src, include, bin, Makefile。这个脚本能一键生成这套结构。

核心功能：

脚本接收一个项目名作为参数（例如在命令行运行 python create_project.py my_c_project）。

自动创建名为 my_c_project 的主文件夹。

在主文件夹内，创建 src, include, bin 等子文件夹。

（进阶）自动在 src 文件夹下创建一个包含 “Hello, World” 模板代码的 main.c 文件，并创建一个基础的 Makefile。

您将接触到的新知识：

处理命令行参数（使用 sys.argv 模块）。

将预设的文本内容写入到新创建的文件中。 
'''