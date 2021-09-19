#include <stdio.h>

static int arr[100000];
static int size;

void	p_recursive(int index)
{
	int tmp;
	if (arr[index/2] < arr[index] && index != 1)
	{
		tmp = arr[index/2];
		arr[index/2] = arr[index];
		arr[index] = tmp;
		p_recursive(index/2);
	}
}

void	insertElement(int key)
{
	arr[++size] = key;
	p_recursive(size);
}

void	exchange(int parent, int child)
{
	int tmp;

	if (arr[parent] < arr[child])
	{
		tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
	}
}

void	m_recursive(int index)
{
	int leftChild = arr[index * 2];
	int rightChild = arr[index * 2 + 1];
	int nextIndex;

	if (!(index <= size))
		return ;
	if (leftChild >= rightChild)
		nextIndex = index * 2;
	else
		nextIndex = index * 2 + 1;
	if (arr[index] < arr[nextIndex])
	{
		exchange(index, nextIndex);
		m_recursive(nextIndex);
	}
}

int		deleteElement()
{
	int maxKey;

	if (size == 0)
		return (0);
	maxKey = arr[1];
	arr[1] = arr[size];
	arr[size] = 0;
	size--;
	m_recursive(1);
	return (maxKey);
}

int		main(void)
{
	int N;
	int key;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &key);
		if (key == 0) {
			printf("%d\n", deleteElement());
		}
		else insertElement(key);
	}
	return (0);
}
