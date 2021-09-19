#include <stdio.h>
#include <stdlib.h>

//node 용
typedef struct node {
	int            data;
	struct node  *next;
  struct node  *prev;
} Node;

//링크드리스트 전체
typedef struct linkedlist {
	struct node *head;
  struct node *tail;
	int    size;
} Linkedlist;

//초기화
void lstinit(Linkedlist *lst)
{
  if (!(lst->head = malloc((sizeof(Node)))))
    return ;
  if (!(lst->tail = malloc((sizeof(Node)))))
    return ;
  lst->head->prev = NULL;
  lst->head->next = lst->tail;
  lst->tail->prev = lst->head;
  lst->tail->next = NULL;
  lst->size = 0;
}

//새 노드 생성
Node	*lstnew(int data)
{
	Node	*list;

	if (!(list = malloc(sizeof(Node))))
    return (0);
	list->data = data;
  list->prev = NULL;
	list->next = NULL;
	return (list);
}

void  add(Node *currNode, Node *newNode)
{
  newNode->next = currNode->next;
  (currNode->next)->prev = newNode;
  newNode->prev = currNode;
  currNode->next = newNode;
}

// 마지막 노드 반환
Node	*getLast(Linkedlist *lst)
{
  if (lst->size >= 1)
    return ((lst->tail)->prev);
  else
    return (NULL);
}

//헤드 바로 뒤에 노드 추가
void	addFront(Linkedlist *lst, Node *newNode)
{
  if (lst && newNode)
  {
	  add(lst->head, newNode);
    (lst->size)++;
  }
}

//맨 뒤에 노드 추가하기
void		addBack(Linkedlist *lst, Node *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
    if (lst->size == 0)
        addFront(lst, new_node);
	else
        add(getLast(lst), new_node);
  (lst->size)++;
}

// 연결리스트 n번째 인덱스에 노드 추가하기
void		addNIndex(Linkedlist *lst, Node *new_node, int n)
{
  //n이 (lst->size)/2 보다 큰지, 작은지
  //크면 tail에서 시작, 작으면 head에서 출발
  //tail에서 시작할 땐, size-n prev를
  //head에서 시작하면 n만큼 next
  if (lst == NULL || new_node == NULL)
		return ;
  if (n < 0 || lst->size < n)
    return ;
  Node *pre = lst->head;
	Node *curr = (lst->head)->next;
  
  for (int i = 0; i < n; i++)
  {
    pre = curr;
    curr = curr->next;
  }
  add(pre, new_node);
  (lst->size)++;
}

int	count(Linkedlist lst)
{
  return (lst.size);
}

//특정 데이터 찾기
Node *search(Node *head, const int data)
{
  Node *curNode = head->next;
  while (curNode)
  {
    if (curNode->data == data)
      return (curNode);
    curNode = curNode->next;
  }
  return (NULL);
}

//전체 조회
void showAll(Node *head)
{
  if (head == NULL)
    return ;
  Node *curNode = head->next;
  while (curNode->next)
  {
    printf("%d\n", curNode->data);
    curNode = curNode->next;
  }
}

//노드삭제
void  delOne(Linkedlist *lst, Node *del)
{
  Node *curNode;

  if (lst == NULL || del == NULL)
    return ;
  if (lst->size >= 1)
  {
    curNode = del;
    (curNode->prev)->next = curNode->next;
    (curNode->next)->prev = curNode->prev;
    free(del);
    (lst->size)--;
  }
}

//첫번째 노드삭제
void  delFront(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, (lst->head)->next);
}

//마지막 노드삭제
void  delLast(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, (lst->tail)->prev);
}


int main(void) {
  int data = 10;
  Linkedlist lst;
  lstinit(&lst);

  addBack(&lst, lstnew(60));
  addBack(&lst, lstnew(70));
  addBack(&lst, lstnew(80));

  showAll(lst.head);
  puts("-----------------");
  
  return (0);
}
