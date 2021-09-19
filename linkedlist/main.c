#include <stdio.h>
#include <stdlib.h>

//node 용
typedef struct s_list {
	int            data;
	struct s_list  *next;
} t_list;

//링크드리스트 전체
typedef struct linkedlist{
	struct s_list *head;
		int size;
} Linkedlist;

//초기화
void lstinit(Linkedlist *lst)
{
  if (!(lst->head = malloc((sizeof(t_list)))))
    return ;
  lst->head->next = NULL;
  lst->size = 0;
}

//새 노드 생성
t_list	*lstnew(int data)
{
	t_list	*list;

	if (!(list = malloc(sizeof(t_list))))
    return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}

//헤드 바로 뒤에 노드 추가
void	lstadd_front(Linkedlist *lst, t_list *new_node)
{
  if (lst && new_node)
  {
	  new_node->next = lst->head->next;
    lst->head->next = new_node;
    (lst->size)++;
  }
}

// 마지막 노드 반환
t_list	*lstlast(t_list *head)
{
	t_list	*lastlst;

	if (head == NULL)
		return (NULL);
	lastlst = head;
	while (lastlst->next)
		lastlst = lastlst->next;
	return (lastlst);
}

int	lstcount(Linkedlist lst)
{
  return (lst.size); 
}

// 연결리스트 맨 뒤에 노드 추가하기
void		lstadd_back(Linkedlist *lst, t_list *new_node)
{
	t_list *last;

	if (lst == NULL || new_node == NULL)
		return ;
	last = lstlast(lst->head);
	last->next = new_node;
  (lst->size)++;
}

//특정 데이터 찾기
t_list *search(t_list *head, const int data)
{
  t_list *cur_node = head->next;
  while (cur_node)
  {
    if (cur_node->data == data)
      return (cur_node);
    cur_node = cur_node->next;
  }
  return (NULL);
}

//전체 조회
void show_all_lst(t_list *head)
{
  if (head == NULL)
    return ;
  t_list *cur_node = head->next;
  while (cur_node)
  {
    printf("%d\n", cur_node->data);
    cur_node = cur_node->next;
  }
}

//노드삭제
void  lstdelone(Linkedlist *lst, t_list *node)
{
  free(node);
  (lst->size)--;
}

//첫번째 노드삭제
void  lstdel_front(Linkedlist *lst)
{
  t_list *cur_node;

  if (lst == NULL)
    return ;
  cur_node = lst->head->next;
  if (cur_node)
  {
    lst->head->next = cur_node->next;
    lstdelone(lst, cur_node);
  }
}

//마지막 노드삭제
void  lstdel_last(Linkedlist *lst)
{
  t_list *pre_node;
  t_list *cur_node;

  pre_node = lst->head;
  cur_node = lst->head->next;
  while (cur_node && cur_node->next)
  {
    pre_node = cur_node;
    cur_node = cur_node->next;
  }
  pre_node->next = NULL;
  lstdelone(lst, cur_node);
}

//특정데이터 노드삭제 --안 됨. 싱글연결리스트의 한계점?
//헤드노드에서 사용할 멤버변수를 위해 구조체에 변수를 추가하는것이 효율적인가?(ex. 현재 방문 위치, 이전 방문위치, 총 노드의 갯수 등) + a (메모리)
void  lstdel_search(Linkedlist *lst, const int data)
{
  t_list *pre_node;
  t_list *cur_node;

  if (lst == NULL)
    return ;
  pre_node = lst->head;
  cur_node = lst->head->next;
  while (cur_node)
  {
    if (cur_node->data == data)
    {
      pre_node->next = cur_node->next;
      lstdelone(lst, cur_node);
      return ;
    }
    pre_node = cur_node;
    cur_node = cur_node->next;
  }
  //1. 연결리스트를 돈다
  //2. cur_node의 데이터가 찾는 데이터와 일치하는지 비교
  // 일치하지 않으면, cur_node = cur_node->next;
  // 일치하면, 

}

void  del_all_lst(Linkedlist *lst)
{
  t_list *tmp;
  t_list *cur_node;

  cur_node = lst->head;
  while (cur_node)
  {
    tmp = cur_node->next;
    lstdelone(lst, cur_node);
    cur_node = tmp;
  }
  lst->head = NULL;
}


int main(void) {
  int data = 10;
  Linkedlist lst;
  lstinit(&lst);

  lstadd_back(&lst, lstnew(60));
  lstadd_back(&lst, lstnew(70));
  lstadd_back(&lst, lstnew(80));
  
  show_all_lst(lst.head);
  puts("-----------------");

  lstdel_front(&lst);
  show_all_lst(lst.head);
  puts("-----------------");
  lstdel_last(&lst);
  show_all_lst(lst.head);
  puts("-----------------");
  lstdel_search(&lst, 30);
  show_all_lst(lst.head);
  puts("-----------------");
  del_all_lst(&lst);
  show_all_lst(lst.head);
  puts("-----------------");
  //printf("%p",search(head, data)); //활용- 해당 데이터를 삭제하기. 특정 데이터 ex.id에 대한 다른 정보들 찾기. 해당 데이터 수정하기.
  

/*
  show_all_lst(head);
  printf("노드의 갯수: %d\n", lstcount(head));
  puts("----------------");

  del_all_lst(&head);
  show_all_lst(head);
  printf("노드의 갯수: %d\n", lstcount(head));
*/
  return (0);
}