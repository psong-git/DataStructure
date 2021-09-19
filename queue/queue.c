
#include "array.h"

//초기화 하기
void	 list_init(list *plist)
{
    plist->arr = malloc(sizeof(Node) * LIST_LEN);
    plist->currDataCnt = 0;
    plist->maxDataCnt = LIST_LEN;
    plist->front = NULL;
    plist->rear  = NULL;
}

void	enqueue(list *plist, char data)
{
	//만약 전체 배열 크기보다 데이터 수가 많으면 -> realloc
	if ((plist->currDataCnt) >= plist->maxDataCnt)
	{
        plist->maxDataCnt = plist->maxDataCnt * 2;
        plist->arr = realloc(plist->arr, (plist->maxDataCnt) * sizeof(Node));	//입력받은 m만큼 추가로 동적할당
	}
  if (plist->currDataCnt <= 0)
  {
      (plist->arr[0]).element = data;
      plist->front = &plist->arr[0];
      plist->rear = &plist->arr[0];
  }
  else
  {
      //데이터를 추가하고, currDataCnt 증가
      plist->arr[plist->currDataCnt].element = data;
      plist->rear = &plist->arr[plist->currDataCnt];
  }
  (plist->currDataCnt)++;
}

//첫번째 데이터 조회
char	peek(list *plist)
{
	if (plist->currDataCnt == 0)
		return (0);
	return ((plist->front)->element);
}

char	dequeue(list *plist)
{
    if (plist->front == NULL && plist->rear == NULL)
      return (0);
    if (plist->currDataCnt == 0) // front == rear
        return (0);
    else if (plist->front == plist->rear)
    {
      (plist->front)->element = 0;
      plist->front = NULL;
      plist->rear = NULL;
      return (0);
    }
    (plist->front)->element = 0;
    (plist->front) = ++(plist->front);
    return (plist->front->element);
}

int		size(list *plist)
{
	return (plist->currDataCnt);
}

void  display(list *plist)
{
  if (!(plist->front))
  {
      printf("큐가 비었다.\n");
    return ;
  }
  int cnt = plist->currDataCnt;
  int i = 0;
  Node *start = plist->front;
  
  while (i < cnt)
  {
    printf("%c\n", start->element);
    (start)++;
    i++;
  }
}
