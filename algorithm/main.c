#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

#define NUM 10
#define MAX 50 
//node 용

//전체 조회
void showAll(List *list)
{
  if (list == NULL)
    return ;
  Node *curNode = list->Head->next;
  while (curNode)
  {
    printf("%d\n", curNode->data);
    curNode = curNode->next;
  }
}

void    MakeSublist(List *Origin, List *listPlus, List *listMinus)
{
    int index_plus = 0;
    int index_minus = 0;
    Node *ret;

    for (int i = 0; i < MAX; i++)
    {
        ret = deleteNodeFront(Origin);
        if (ret->data < 0)
        {
            addNodeIndex(ret, listMinus, index_minus);
            index_minus++;
        }
        else
        {   
            addNodeIndex(ret, listPlus, index_plus);
            index_plus++;
        }
    }
}

void    bucketClear(List *list, List **bucket)
{
    Node *ret;
    for (int i = 0; i < NUM; i++)
        while (bucket[i]->size)
        {
            ret = deleteNodeFront(bucket[i]);
            addNodeBack(ret, list);
        }
}

int findDigitMax(List *list)
{
    Node *curr = list->Head->next;
    int max = curr->data;
    int digit;

    while (curr)
    {
        if (curr->data > max)
            max = curr->data;
        curr = curr->next;
    }
    printf("max :%d ", max);
    while (max)
    {
        max /= 10;
        digit++;
    }
    printf("digit : %d\n", digit);
    return (digit);
}

void    RadixSort(List *list, List **bucket)
{
    int i = 1;
    int index;
    int digit = findDigitMax(list);

    Node *ret;
    for (int j = 0; j < digit; j++)
    {    
        Node *curr = list->Head->next;
        while (curr)
        {
            curr = curr->next;
            ret = deleteNodeFront(list);
            index = (ret->data % (10 * i)) / i;
            addNodeBack(ret, bucket[index]);
        }
        bucketClear(list, bucket);
        i *= 10;
    }
}

int main(void) {
    List  **bucket;
    List  *listOrigin;
    List  *listPlus;
    List  *listMinus;
    int num;
    int count;

    srand(time(NULL));
    bucket = (List **)calloc(NUM, sizeof(List *));
    for (int i = 0; i < NUM; i++)
        bucket[i] = newList();
    listOrigin = newList();
    listPlus = newList();
    listMinus = newList();
    for (int i = 0; i < MAX; i++)
    {
        num = rand() % 99999 * (1 + (-2 * (rand() % 2)));
        addNodeIndex(newNode(num), listOrigin, i);
    }
  puts("--------Origin--------");
  showAll(listOrigin);
  MakeSublist(listOrigin, listPlus, listMinus);
  puts("--------Plus--------");
  showAll(listPlus);
  RadixSort(listPlus, bucket);
  puts("--------Plus after--------");
  showAll(listPlus);
  //puts("--------Origin after--------");
  //showAll(listOrigin);
  puts("--------Minus-------");
  showAll(listMinus);
  
  return (0);
}
