#include "array.h"

int main(void)
{
	//arraylist의 생성 및 초기화
	list	list;    
	list_init(&list); //관련된 변수들의 초기화

	//5개의 데이터 저장
	enqueue(&list, 'A');
	enqueue(&list, 'B');
	enqueue(&list, 'C');
	enqueue(&list, 'D');
	enqueue(&list, 'E');
    

    printf("\n");
    printf("전체 노드의 값을 출력해봅시다.\n");
    display(&list);

    printf("\n");
    printf("peek 결과는 %c 입니다.\n", peek(&list));

    dequeue(&list);
    dequeue(&list);
    dequeue(&list);

    printf("\n");
    printf("바뀐 노드의 값을 출력해봅시다.\n");
    display(&list);
    printf("\n");

    dequeue(&list);
    dequeue(&list);
    dequeue(&list);

    printf("\n");
    printf("바뀐 노드의 값을 출력해봅시다.\n");
    display(&list);
    printf("\n");

    return (0);
}
