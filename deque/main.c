#include "deque.h"

int main(void)
{
  int data = 10;

  Linkedlist lst;
  lstinit(&lst);

  insertpFrontNode(&lst, lstnew('C'));
  insertpFrontNode(&lst, lstnew('B'));
  insertpFrontNode(&lst, lstnew('A'));

    printf("\n");
    printf("노드를 출력해봅시다(^_^)b\n");
    display(lst.pFrontNode);

    insertpRearNode(&lst, lstnew('E'));
    insertpRearNode(&lst, lstnew('F'));
    insertpRearNode(&lst, lstnew('G'));

    printf("\n");
    printf("노드를 출력해봅시다\\(^_^)/\n");
    display(lst.pFrontNode);

    deletepFrontNode(&lst);
    deletepFrontNode(&lst);
    deletepFrontNode(&lst);
    deletepFrontNode(&lst);

    printf("\n");
    printf("노드를 출력해봅시다v(^_^)v\n");
    display(lst.pFrontNode);

    deletepRearNode(&lst);
    deletepRearNode(&lst);
    deletepRearNode(&lst);

    printf("\n");
    printf("노드를 출력해봅시다(o_o)v\n");
    display(lst.pFrontNode);



  // insertpRearNode(Linkedlist *lst, Node *new_node)
  // size(Linkedlist lst)
  // deletepFrontNode
  // deletepRearNode
  return (0);
}
