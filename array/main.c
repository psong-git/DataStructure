#include <stdio.h>
#include "arraylist.h"

int main(void)
{
	//arraylist의 생성 및 초기화
	list	list;
	int		data;
	list_init(&list);

	//5개의 데이터 저장
	list_insert(&list, 11);
	list_insert(&list, 11);
	list_insert(&list, 22);
	list_insert(&list, 22);
	list_insert(&list, 33);

	//저장된 데이터의 전체 출력
	printf("현재 데이터의 수: %d \n", list_count(&list));

	if (list_first(&list, &data))
	{
		printf("%d ", data);
		while (list_next(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	//숫자22를 찾아 모두 삭제
	if (list_first(&list, &data))
	{
		if (data == 22)
			list_remove(&list);
		while (list_next(&list, &data))
		{
			if (data == 22)
				list_remove(&list);
		}
	}
	//삭제 후 남은 데이터 출력
	printf("현재 데이터의 수: %d \n", list_count(&list));

	if (list_first(&list, &data))
	{
		printf("%d ", data);
		while (list_next(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return (0);
}
