#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# define TRUE			1
# define FALSE 			0
# define LIST_LEN		100

#include <stdio.h>

typedef int list_data;

typedef struct __ArrayList
{
	list_data arr[LIST_LEN];
	int num_of_data;
	int cur_pos;
} ArrayList;

typedef ArrayList list;

void 		list_init(list *plist);
void 		list_insert(list *plist, list_data data);
int 		list_first(list *plist, list_data *pdata);
int 		list_next(list *plist, list_data *pdata);
int 		list_count(list *plist);
list_data 	list_remove(list *plist);

#endif
