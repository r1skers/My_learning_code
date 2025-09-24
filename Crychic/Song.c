//命令行数字音乐库
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Song{
    char title[100];
    char artist[100];
    struct Song *next;
}SongNode;
//添加歌曲
void addSong(SongNode **head, const char *title, const char *artist){
    SongNode *newNode = (SongNode*)malloc(sizeof(SongNode));
    if(newNode == NULL){
        printf("内存分配失败！\n");
        return;
    }
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    newNode->next = *head;
    *head = newNode;
    printf("已添加歌曲: \"%s\" by %s\n", title, artist);
}
//释放内存
void freeLibrary(SongNode **head) {
    SongNode *current = *head;
    SongNode *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}
//查找歌曲
SongNode* findSong(SongNode *head, const char *title)
{
    SongNode *current = head;
    while (current != NULL)
    {
        if(strcmp(current->title, title) == 0)
        {

            return current;
        }
        current = current->next;
        }
    return NULL;
};

//主函数
int main(){
    SongNode *music_library_head = NULL;
    printf("--- 开始添加歌曲 ---\n");
    addSong(&music_library_head, "Shape of You", "Ed Sheeran");
    addSong(&music_library_head, "Blinding Lights", "The Weeknd");
    addSong(&music_library_head, "Levitating", "Dua Lipa");
    printf("--- 歌曲添加完毕 ---\n");
    printf("--- 开始查找歌曲 ---\n");
    const char *searchTitle = "Blinding Lights";
    SongNode *foundSong = findSong(music_library_head, searchTitle);

    if (foundSong != NULL) {
        printf("找到了歌曲: \"%s\", 演唱者: %s\n", foundSong->title, foundSong->artist);
    } else {
        printf("未找到歌曲: \"%s\"\n", searchTitle);
    }
    
    const char *searchTitle2 = "Hotel California";
    foundSong = findSong(music_library_head, searchTitle2);

    if (foundSong != NULL) {
        printf("找到了歌曲: \"%s\", 演唱者: %s\n", foundSong->title, foundSong->artist);
    } else {
        printf("未找到歌曲: \"%s\"\n", searchTitle2);
    }
    printf("--- 查找结束 ---\n\n");
    freeLibrary(&music_library_head);
    return 0;
}
