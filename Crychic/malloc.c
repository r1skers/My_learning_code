//为单个整数分配内存
#include <stdio.h>
#include <stdlib.h>
 int main(){
    int *p;//声明一个整型指针
    p=(int *)malloc(sizeof(int));//为一个整数分配内存
    if(p==NULL){//检查内存分配是否成功
        printf("内存分配失败\n");
        return 1;
    }
    *p=42;//将值赋给分配的内存
    printf("分配的整数值: %d\n",*p);//打印分配的整数值
    free(p);//释放分配的内存
    return 0;
 }









 //创建一个动态的学生“卡片”
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
    int id;
    char name[50];
} Student;

int main() {
    // 1. 声明一个指向 Student 结构体的指针
    Student *stu_p;

    // 2. 申请内存：大小正好是一个 Student 结构体的大小
    stu_p = (Student*)malloc(sizeof(Student));

    if (stu_p == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 3. 使用内存：为结构体成员赋值
    //    因为 stu_p 是指针，所以用 "->" 符号访问成员
    stu_p->id = 101;
    strcpy(stu_p->name, "Tanaka"); // 对于字符串，需要用 strcpy

    // 4. 验证：打印学生信息
    printf("学生 ID: %d, 姓名: %s\n", stu_p->id, stu_p->name);

    // 5. 释放内存
    free(stu_p);
    stu_p = NULL;

    return 0;
}







//手动连接两个学生节点
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct StudentNode {
    int id;
    char name[50];
    struct StudentNode *next; // 灵魂所在！
} StudentNode;

int main() {
    // 创建第一个节点 (学生A)
    StudentNode *nodeA = (StudentNode*)malloc(sizeof(StudentNode));
    nodeA->id = 101;
    strcpy(nodeA->name, "Sato");
    
    // 创建第二个节点 (学生B)
    StudentNode *nodeB = (StudentNode*)malloc(sizeof(StudentNode));
    nodeB->id = 102;
    strcpy(nodeB->name, "Suzuki");

    // --- 关键操作：手动连接！ ---
    // 让 A 的 next 指针指向 B 的地址
    nodeA->next = nodeB;
    // B 是最后一个，所以它的 next 指向 NULL
    nodeB->next = NULL;

    // --- 验证连接 ---
    printf("第一个学生是: %s\n", nodeA->name);
    printf("通过A找到的第二个学生是: %s\n", nodeA->next->name); // 看！我们通过 nodeA->next 访问到了 nodeB

    // 释放内存 (必须一个个释放)
    free(nodeA);
    free(nodeB);
    nodeA = NULL;
    nodeB = NULL;

    return 0;
}




//一个简单的命令行“待办事项” (To-Do List) 管理器
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Task{
    char description[100];
    struct Task *next;
}Task;

int main(){
    Task *taskA=(Task *)malloc(sizeof(Task));
    if(taskA==NULL){
        printf("内存分配失败\n");
        return 1;
    }
    strcpy(taskA->description,"Think about the list");
    Task *taskB=(Task *)malloc(sizeof(Task));
    if(taskB==NULL){
        printf("内存分配失败\n");
        free(taskA);
        taskA=NULL;
        return 1;
    }
    strcpy(taskB->description,"Write the to-do list");
    taskA->next=taskB;
    printf("First task: %s\n",taskA->description);
    printf("Next task: %s\n",taskA->next->description);
    free(taskA);
    free(taskB);
    taskA=NULL;
    taskB=NULL;
    return 0;

}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定义“待办事项”节点结构体
typedef struct Task {
    char description[200];    // 任务描述
    struct Task *next;        // 指向下一个任务
} TaskNode;

// 2. 编写 addTask 函数
//    注意这里我们用了 TaskNode **head，因为我们要修改 main 函数里的 head 指针
void addTask(TaskNode **head, const char *description) {
    // A. 为新任务申请内存
    TaskNode *newNode = (TaskNode*)malloc(sizeof(TaskNode));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return;
    } 

    // B. 填充新任务的数据
    strcpy(newNode->description, description);

    // C. 将新任务连接到列表的头部
    newNode->next = *head; // 新节点的next指向原来的第一个节点
    *head = newNode;       // head指针指向这个新节点，使其成为新的第一个节点
    
    printf("已添加任务: \"%s\"\n", description);
}

int main() {
    // 初始化一个空的列表，头指针为 NULL
    TaskNode *todo_list_head = NULL;

    printf("--- 开始添加任务 ---\n");
    
    // 3. 调用函数，创建列表
    addTask(&todo_list_head, "晚上 7 点去健身房");
    addTask(&todo_list_head, "学习C语言指针");
    addTask(&todo_list_head, "给妈妈打电话");

    printf("--- 任务添加完毕 ---\n");

    // ... 后面我们会在这里添加显示和释放内存的代码 ...
    
    // (为了完整性，暂时手动释放一下我们知道的这3个节点，后面会用函数替代)
    TaskNode *temp;
    while(todo_list_head != NULL) {
        temp = todo_list_head;
        todo_list_head = todo_list_head->next;
        free(temp);
    }
    
    return 0;
}

// 1. 编写 showTasks 函数
void showTasks(TaskNode *head) {
    printf("\n--- 当前的待办事项 ---\n");
    if (head == NULL) {
        printf("列表是空的，太棒了！\n");
        return;
    }
    
    TaskNode *current = head; // 创建一个临时指针用于遍历，不破坏原始的 head
    int count = 1;
    
    while (current != NULL) {
        printf("%d. %s\n", count, current->description);
        current = current->next; // 移动到下一个节点
        count++;
    }
    printf("-----------------------\n");
}

/*
  修改你的 main 函数，在添加任务后调用 showTasks:

  int main() {
      TaskNode *todo_list_head = NULL;
      
      // ... addTask 的调用不变 ...
      addTask(&todo_list_head, "晚上 7 点去健身房");
      addTask(&todo_list_head, "学习C语言指针");
      addTask(&todo_list_head, "给妈妈打电话");

      // 2. 在这里调用新函数
      showTasks(todo_list_head);

      // ... 释放内存的代码 ...
      return 0;
  }
*/

// (继续添加新函数)

// 1. 编写 completeFirstTask 函数
void completeFirstTask(TaskNode **head) {
    // 检查列表是否为空
    if (*head == NULL) {
        printf("没有任务可以完成。\n");
        return;
    }
    
    // 创建一个临时指针指向要被删除的第一个节点
    TaskNode *nodeToDelete = *head;
    
    printf("\n--- 完成任务: \"%s\" ---\n", nodeToDelete->description);
    
    // 将 head 指针移动到第二个节点，使其成为新的头
    *head = nodeToDelete->next;
    
    // 释放原先第一个节点的内存
    free(nodeToDelete);
    nodeToDelete = NULL; // 安全措施
}

/*
  再次修改你的 main 函数，加入删除操作:

  int main() {
      // ...
      addTask(&todo_list_head, "晚上 7 点去健身房");
      addTask(&todo_list_head, "学习C语言指针");
      addTask(&todo_list_head, "给妈妈打电话");

      showTasks(todo_list_head); // 显示初始列表

      // 2. 调用删除函数
      completeFirstTask(&todo_list_head);

      // 3. 再次显示，验证结果
      showTasks(todo_list_head);
      
      // ...
  }
*/