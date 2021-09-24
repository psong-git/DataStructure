#include "linkedlist.h"
#include <time.h>

int	main()
{
	srand(time(NULL));
	
	int arr[2] = {0,};
	int len = sizeof(arr) / sizeof(int);
	int	index;
	Node *temp;

	List *list = newList();
	
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 9999;
	for (int i = 0; i <len; i++)
	{
		index = findIndex(list,arr[i]);
		addNodeIndex(newNode(arr[i]), list, index);
	}
	Node *curr = list->Head->next;
	for (int i = 0; i < len; i++)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
}
