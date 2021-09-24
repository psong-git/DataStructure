#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

void	Swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int ret;
void	Insert(int arr[], int insert, int origin)
{
	int tmp;

	tmp = arr[insert];
	arr[insert] = arr[origin];
	for (int i = origin; i > insert; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[insert + 1] = tmp;
}
void	SelectionSort(int arr[], int size)
{
	int	min;
	int index = 0;

	for (int j = 0; j < size; j++)
	{	
		min = INT_MAX;
		for (int i = j; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				index = i;
			}
		}
		Swap(&arr[j], &arr[index]);
		ret++;
	}
}

void	BubbleSort(int arr[], int size)
{
	for (int j = 0; j < size; j++)
	{	
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				Swap(&arr[i], &arr[i + 1]);
		}
		size--;
	}
}

void	QuickSort(int arr[], int left, int right)
{
	int	pivot_index = (left + right) / 2;
	int pivot_value = arr[pivot_index];
	int left_init = left;
	int	right_init = right;

	if (left >= right)
		return ;
	Swap(&arr[pivot_index], &arr[right]);
	pivot_index = right;
	//right--;
	while (left < right)
	{	
		while (left < right)
		{
			if (arr[left] >= pivot_value)
				break;
			left++;
		}	
		while (left < right)
		{
			if (arr[right] < pivot_value)
				break;
			right--;
		}
		if (left >= right)
			Swap(&arr[pivot_index], &arr[left]);
		else
			Swap(&arr[left], &arr[right]);
	}
	QuickSort(arr, left_init, left - 1);
	QuickSort(arr, left + 1, right_init);
}

void	InsertSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				Insert(arr, j, i);
				break;
			}
		}
	}
}

void	ShellInsert(int arr[], int insert, int origin, int step)
{
	int tmp;

	tmp = arr[insert];
	arr[insert] = arr[origin];
	for (int i = origin; i > insert; i -= step)
	{
		arr[i] = arr[i - step];
	}
	arr[insert + step] = tmp;
}

void	ShellSort(int arr[], int size)
{
	int	increment = size / 2;

	while (increment)
	{	
		for (int k = 0; k < increment; k++)
			for (int i = k; i < size; i += increment)
			{
				for (int j = k; j < i; j += increment)
				{
					if (arr[j] > arr[i])
					{
						ShellInsert(arr, j, i, increment);
						printf("increment : %d\n", increment);
						for (int i = 0; i < size; i++)
							printf("%d ", arr[i]);
						printf("\n");
						break;
					}
				}
			}
		increment /= 2;
	}
}

int	findMin(int arr[], int start, int end)
{
	int min = INT_MAX;
	int	min_index = 0;

	for (int i = start; i < end + 1; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
	}
	return (min_index);
}
int sorted[100];

void Merge(int a[], int start, int middle, int end) {
 
    int i, j, k; //각각 start middle middle+1 에 해당
    i = start;
    j = middle + 1;
    k = start;
 
    // 3가지의 경우중에 교차되는 경우먼저따져보자
    while (i <= middle && j <= end) {
  
 
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        }
        else { //그 반대의 경우라면
            sorted[k] = a[j];
            j++;
             }
        k++;//정렬배열의 다음 칸에 담아야 하므로
    }
 
    //교차되는 경우가 아니라 특정 하나가 먼저 채워진다면?
    if (i > middle) {// i가 먼저채워졌기때문에 middle보다 커진것
        for (int t = j; t <= end; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    else{ // j가 먼저채워졌기때문에
             for (int t = i; t <= middle; t++) {
                         sorted[k] = a[t];
                         k++;
                        }
    }
    //정렬된 배열을 삽입
 
    for (int t = start; t <= end; t++) {
        a[t] = sorted[t];
                                        }
}
void	MergeSort(int arr[], int start, int end)
{
	if (start == end)
		return ;
	int split = (start + end) / 2;
	
	MergeSort(arr, start, split);
	MergeSort(arr, split + 1, end);
	Merge(arr, start, split, end);
}



int	isSorted(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

int	main()
{
	int	arr[100] = {0,};
	int arr2[100] = {0,};
	srand(time(NULL));
	int	len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len; i++)
	{	arr[i] = rand() % 9999 * (1 + (-2 * (rand() % 2)));
		arr2[i] = arr[i];
	//Swap(&arr[0], &arr[1]);
	}
	
	printf("init:");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	//SelectionSort(arr, len);
	//BubbleSort(arr, len);
	//printf("%d\n", len);
	//QuickSort(arr, 0, len - 1);
	//Insert(arr, 1, 9);
	//InsertSort(arr,len);
	//ShellSort(arr, len);
	MergeSort(arr, 0, len - 1);
	printf("%d\n", ret);	
	ret =  0;
	SelectionSort(arr2, len);
	printf("result:");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("%d\n", ret);	
	if (!isSorted(arr, len))
		printf("Array1 is Not Sorted!!!\n");
	return (0);
}
