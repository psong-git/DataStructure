#ifndef ARRAY_H
# define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

# define TRUE	1
# define FALSE 	0
# define LIST_LEN   5

//노드용 구조체
typedef struct __ArrayQueueNode
{
    char element;
} Node;

//전체배열큐 구조체
typedef struct __ArrayList
{
    Node      *arr;
    int       currDataCnt; // 현재 노드 갯수
    int       maxDataCnt;  // 최대 노드 갯수
    Node      *front;
    Node      *rear;
} ArrayList;

typedef ArrayList list; ////

void	list_init(list *plist);
void	enqueue(list *plist, char data);
char	peek(list *plist);
char	dequeue(list *plist);
int		size(list *plist);
void  display(list *plist);

#endif
