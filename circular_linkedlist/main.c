#include <stdio.h>
#include <stdlib.h>

//node 용
typedef struct node {
	int            data;
	struct node  *next;
} Node;

//링크드리스트 전체
typedef struct linkedlist {
  struct node *tail;
	int    size;
} Linkedlist;


//초기화
void lstinit(Linkedlist *lst, int data)
{
  if (!(lst->tail = malloc(sizeof(Node))))
    return ;
  (lst->tail)->next = lst->tail;
  (lst->tail)->data = data;
  lst->size = 1;
}

//새 노드 생성
Node	*lstnew(int data)
{
	Node	*list;

	if (!(list = malloc(sizeof(Node))))
    return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}


//더미노드 없이, 모든 노드가 데이터를 갖고 있다
//이후 노드를 생성해 덧붙일 때 그 노드가 tail이 됨
//첫 노드는 다음 노드로 자기 자신을 가르킨다
void  addBack(Linkedlist *lst, Node *newNode)
{
  Node *head;

  if (!lst || !newNode)
    return ;
  
  head = (lst->tail)->next;
  (lst->tail)->next = newNode;
  lst->tail = newNode;

  newNode->next = head;
  (lst->size)++;
}

//첫번째 노드자리에 노드추가
void	addFront(Linkedlist *lst, Node *newNode)
{
  if (!lst || !newNode)
    return ;
  
  newNode->next = (lst->tail)->next;
  (lst->tail)->next = newNode;
  (lst->size)++;
}

// 연결리스트 n번째 인덱스에 노드 추가하기
void		addNIndex(Linkedlist *lst, Node *newNode, int n)
{
  Node *prev;
  Node *curr;

  if (lst == NULL || newNode == NULL)
		return ;
  if (n < 0 || lst->size < n)
    return ;
  prev = lst->tail;
  curr = prev->next;
	
  for (int i = 0; i < n; i++)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = newNode;
  newNode->next = curr;
  if (lst->size == n)
    lst->tail = newNode;
  (lst->size)++;
}

// 마지막 노드 반환
Node	*getLast(Linkedlist *lst)
{
  if (!lst)
    return (NULL);
  return (lst->tail);
}

int	count(Linkedlist lst)
{
  return (lst.size);
}

//특정 데이터 찾기
Node *search(Linkedlist *lst, const int data)
{
  if (lst)
  {
    Node *curNode = lst->tail;
    for (int i = 0; i< lst->size; i++)
    {
      if (curNode->data == data)
        return (curNode);
      curNode = curNode->next;
    }
  }
  return (NULL);
}

//전체 조회
void showAll(Linkedlist *lst)
{
  if (lst == NULL || lst->size == 0)
    return ;
  Node *curNode = (lst->tail)->next;
  for (int i = 0; i < lst->size; i++)
  {
    printf("%d\n", curNode->data);
    curNode = curNode->next;
  }
}

//노드삭제
void  delOne(Linkedlist *lst, Node *one)
{
  Node *prev;
  Node *next;
  Node *curr;

  if (lst == NULL || one == NULL)
    return ;
  curr = one;
  next = curr->next;
  for (int i = 0; i < (lst->size) - 1; i++)
  {
    curr = curr->next;
  }
  prev = curr;
  
  (lst->size)--;
  prev->next = next;
  if (lst->tail == one)
    lst->tail = prev;
  free(one);
}


//첫번째 노드삭제
void  delFront(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, (lst->tail)->next);
}

//마지막 노드삭제
void  delLast(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, lst->tail);
}

void  delSearch(Linkedlist *lst, const int data)
{
  delOne(lst, search(lst, data));
}

void  delAll(Linkedlist *lst)
{
  Node *curNode;

  curNode = lst->tail;
  for (int i = 0; i < lst->size; i++)
  {
    curNode = curNode->next;
    free(curNode);
  }
  lst->tail = NULL;
  lst->size = 0;
}

int main(void) {
  Linkedlist lst;
  lstinit(&lst, 10);

  addFront(&lst, lstnew(10000));
  addFront(&lst, lstnew(20000));
  //addNIndex(&lst, lstnew(7070), 1);
  //delOne(&lst, lst.tail);
  showAll(&lst);

  //addFront(&lst, lstnew(10));
  //addBack(&lst, lstnew(60));
  //addBack(&lst, lstnew(70));
  //addBack(&lst, lstnew(80));
  puts("-----------------");

  //delLast(&lst);
  ////showAll(&lst);
  //puts("-----------------");

  //delFront(&lst);
  delSearch(&lst, 10);
  showAll(&lst);
  puts("-----------------");

  //delAll(&lst);
  //showAll(&lst);
  //puts("-----------------");

/*
  addNIndex(&lst, lstnew(3333), 0);
  showAll(lst.head);
  puts("-----------------");

  addNIndex(&lst, lstnew(6666), 1);
  showAll(lst.head);
  puts("-----------------");

  addNIndex(&lst, lstnew(9999), 10);
  showAll(lst.head);
  puts("-----------------");

  addNIndex(&lst, lstnew(7777), 11);
  showAll(lst.head);
  puts("-----------------");

  delFront(NULL);
  showAll(lst.head);
  puts("-----------------");
  
  delLast(NULL);
  showAll(lst.head);
  puts("-----------------");
  
  delSearch(&lst, 30);
  showAll(lst.head);
  puts("-----------------");
  
  delAll(&lst);
  showAll(lst.head);
  puts("-----------------");
  //printf("%p",search(head, data)); //활용- 해당 데이터를 삭제하기. 특정 데이터 ex.id에 대한 다른 정보들 찾기. 해당 데이터 수정하기.
  show_all_lst(head);
  printf("노드의 갯수: %d\n", lstcount(head));
  puts("----------------");

  del_all_lst(&head);
  show_all_lst(head);
  printf("노드의 갯수: %d\n", lstcount(head));
  */
  return (0);
}
