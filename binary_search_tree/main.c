#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int		data;
	struct s_node *parent;
	struct s_node *left;
	struct s_node *right;
}	node;

static node *root;
static int size;

node	*newNode(int data)
{
	node *tmp;

	tmp = malloc(sizeof(node) * 1);
	tmp->data = data;
	tmp->parent = NULL;
	tmp->left = NULL;
	tmp->right = NULL;
	size++;
	return (tmp);
}

node	*search(node *node, int data)
{
	struct s_node *tmp;

	if (node == NULL)
		return NULL;
	if (node->data == data)
		return node;
	else if (node->data > data)
		tmp = search(node->left, data);
	else
		tmp = search(node->right, data);
	return tmp;
}

void	insertElement(node *new, node *node)
{
	if (!(node))
		return ;
	if (node->data > new->data)
	{
		if (node->left == NULL)
		{
			node->left = new;
			new->parent = node;
		}
		else
			insertElement(new, node->left);
	}
	else if (node->data < new->data)
	{
		if (node->right == NULL)
		{
			node->right = new;
			new->parent = node;
		}
		else
			insertElement(new, node->right);
	}
	else
		return ;
}

void	inorder(node *node)
{
	if (node == NULL)
		return ;
	inorder(node->left);
	printf("%d\n", node->data);
	inorder(node->right);
}

void	deleteNode(node *node)
{
	node->left = NULL;
	node->right = NULL;
	node->data = 0;
	free(node);
	node = NULL;
	size--;
}

node	*left(node *node)
{
	struct s_node *tmp;
	if (node->left == NULL)
		return (node);
	tmp = left(node->left);
	return (tmp);
}

void	deleteRoot(void)
{
	if (root->left == NULL && root->right == NULL)
	{
		deleteNode(root);
		root = NULL;
	}
	else if (root->left && root->right)
	{
		node *ptr;
		
		ptr = left(root->right);
		root->data = ptr->data;
		if (ptr->right)
		{
			(ptr->parent)->left = ptr->right;
			deleteNode(ptr);
		}
		else
		{
			(ptr->parent)->left = NULL;
			deleteNode(ptr);
		}
		ptr = NULL;
	}
	else if (root->left || root->right)
	{
		node *ptr;
		if (root->left)	
			ptr = root->left;
		else
			ptr = root->right;
		deleteNode(root);
		root = ptr;
	}	
}

void	deleteElement(node *node, int data)
{
	struct s_node *del;
	struct s_node *rsn;
	struct s_node *tmp;
	
	del = search(node, data);
	if (del == NULL)
		return ;
	if (del == root)
	{
		deleteRoot();
		return ;
	}
	if (del->left == NULL && del->right == NULL)
	{
		tmp = del->parent;
		if (tmp->left == del)
			tmp->left = NULL;
		else
			tmp->right = NULL;
		deleteNode(del);
	}
	else if (del->left && del->right)
	{
		int temp;
		
		temp = del->data;
		rsn = left(del->right);
		del->data = rsn->data;
		if (rsn->right)
		{	
			(rsn->parent)->left = rsn->right;
			deleteNode(rsn);
		}
		else
		{
			(rsn->parent)->left = NULL;
			deleteNode(rsn);
		}
		rsn = NULL;
	}
	else if (del->left || del->right)
	{
		tmp = del->parent;
		if (tmp->left == del)
		{
			if (del->left)
				tmp->left = del->left;
			else
				tmp->left = del->right;
		}
		else
		{
			if (del->left)
				tmp->right = del->left;
			else
				tmp->right = del->right;
		}
		deleteNode(del);
	}
}

int		main(void)
{
	int N;
	int data;

	printf("몇개의 인자를 입력할까요? : ");
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		if (i == 0)
			root = newNode(data);
		else
			if (search(root, data) == NULL)
				insertElement(newNode(data), root);
	}
	deleteElement(root, 3);
	puts("-------inorder-------");
	//printf("%d\n", root->data);
	//printf("%d\n", root->left->data);
	//printf("%d\n", root->right->data);
	//printf("%d\n", root->right->right->data);
	//printf("%d\n", root->left->left->data);
	//printf("%d\n", root->left->right->data);
	//printf("%d\n", root->left->right->left->data);
	inorder(root);
	return (0);	
}
