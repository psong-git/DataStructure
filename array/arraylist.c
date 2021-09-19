
#include "arraylist.h"

//초기화 하기
void	 list_init(list *plist)
{
	plist->num_of_data 	= 0;
	plist->cur_pos 		= -1;
}

//데이터 삽입
void	list_insert(list *plist, list_data data)
{
	//만약 전체 배열 크기보다 데이터 수가 많으면
	if ((plist->num_of_data) >= LIST_LEN)
	{
		puts("데이터가 꽉 차서 저장할 수 없습니다");
		return ;
	}

	//데이터를 추가하고, num_of_data 증가
	plist->arr[plist->num_of_data] = data;
	(plist->num_of_data)++;
}

//첫번째 데이터 조회
int	list_first(list *plist, list_data *pdata)
{
	if (plist->num_of_data == 0)
		return (FALSE);

	plist->cur_pos = 0; //참조 위치 초기화. 첫번제 데이터의 참조
	*pdata = plist->arr[0];
	return (TRUE);
}

int	list_next(list *plist, list_data *pdata)
{
	if (plist->cur_pos >= (plist->num_of_data) - 1)
		return (FALSE);

	(plist->cur_pos)++;
	*pdata = plist->arr[plist->cur_pos];
	return (TRUE);
}

list_data	list_remove(list *plist)
{
	int cur_pos = plist->cur_pos;
	int num_of_data = plist->num_of_data;
	int i;
	list_data removed_data = plist->arr[cur_pos];

	//삭제를 위한 데이터의 이동
	for (i = cur_pos; i < num_of_data - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->num_of_data)--;
	(plist->cur_pos)--; //참조 위치 하나 되돌리기
	return (removed_data);
}

int		list_count(list *plist)
{
	return (plist->num_of_data);
}
