#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_OF_STUDENT 5

typedef struct {
    char id[10];
    int score;
} STUDENT;

void copy_string(char *target, char *source) {
    while (*source) {
        *target = *source; // 將 source 字串複製到 target 字串中
        source++;
        target++;
    }
    *target = '\0';
}

void swap1(STUDENT s1, STUDENT s2) {
    STUDENT temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

void swap2(STUDENT *s1, STUDENT *s2) {
    STUDENT temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void foo(STUDENT *students) {
    for (int i = 0; i < NUM_OF_STUDENT; i++) {
        for (int j = i + 1; j < NUM_OF_STUDENT; j++) {
            if (students[i].score > students[j].score) {
                printf("%d\n", students[i].score); 
                printf("%d\n", students[j].score); 
                swap1(*(students + i), *(students + j)); // 使用 swap1() 函式交換學生資料
            }
        }
    }
}

void bar(STUDENT *students) {
    for (int i = 0; i < NUM_OF_STUDENT; i++) {
        for (int j = i + 1; j < NUM_OF_STUDENT; j++) {
            if (students[i].score < students[j].score) {
                printf("%d\n", students[i].score); 
                printf("%d\n", students[j].score); 
                swap2(&students[i], &students[j]); // 使用 swap2() 函式交換學生資料
            }
        }
    }
}

int main() {
    char *ids[NUM_OF_STUDENT] = {"t001", "t002", "t003", "t004", "t005"};
    int scores[NUM_OF_STUDENT] = {85, 70, 95, 60, 75};
    STUDENT *students;
    students = (STUDENT *)malloc(NUM_OF_STUDENT * sizeof(STUDENT)); // 分配記憶體
    // 初始化每個學生的 id 和 score
    for (int i = 0; i < NUM_OF_STUDENT; i++) {
        copy_string(students[i].id, ids[i]);
        (students + i)->score = scores[i]; // 使用指標操作設定學生的成績
    }
    foo(students); // 使用 foo() 函式排序學生資料
    printf("%s\n", students[0].id); // 輸出成績最佳的學生的 id
    bar(students); // 使用 bar() 函式排序學生資料
    printf("%s\n", students[0].id); // 輸出成績最差的學生的 id
    return 0;
}
