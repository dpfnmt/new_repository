#include"Tree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int *pindex)
{
	assert(a);
	if (a[*pindex] == '#')
	{
		++(*pindex);
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pindex];
		++(*pindex);
		root->_left = BinaryTreeCreate(a, pindex);
		root->_right = BinaryTreeCreate(a, pindex);
		return root;
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return 0;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);

	free(root);
	root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
}

int BinaryTreeLeafSize(BTNode* root)   //二叉树的元素个数
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}


int BinaryTreeLevelKSize(BTNode* root, int k)  //二叉树第k层叶子节点个数
{
	if (root == NULL)
		return 0;
	if (1 == k)  //这里不是判断root的，是判断树节点的个数的大小，在根节点的时候，只有一个；
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空 
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)   //还没有实现出来
//{
//	BTNode* cur = NULL;
//	if (root)
//	{
//		if (root->_data = x)
//		{
//			return root;
//		}
//		else
//		{
//			if (root->_left == NULL && root->_right == NULL)
//				return NULL;
//			else
//			{
//				if ((cur = BinaryTreeFind(root->_left, x) != NULL) || 
//					(cur = BinaryTreeFind(root->_right, x) != NULL))
//					return cur;
//			}
//		}
//	}
//	return NULL;
//}
// 递归遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	else
		printf("%c", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	else
		BinaryTreeInOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreeInOrder(root->_right);
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	else
		BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c", root->_data);
}
// 非递归遍历


// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;	
	QueueInit(&q);	
	if (root != NULL)	
	{
		QueuePush(&q, root);		
		while (QueueEmpty(&q) != 0)		
		{ 
			BTNode* front = QueueFront(&q);			
			QueuePop(&q);			
			printf("%c ", front->_data);			
			if (front->_left)			
			{ 
				QueuePush(&q, front->_left); 
			}			
			if (front->_right)			
			{ 
				QueuePush(&q, front->_right); 
			} 
		} 
	}	
	printf("\n");
	
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode* cur;
	if (root == NULL)
		return 1;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	QueuePush(&q, root);
	while (q._head->_data != NULL)
	{
		cur = q._head->_data;
		QueuePop(&q);
		QueuePush(&q, cur->_left);
		QueuePush(&q, cur->_right);
	}
	while (!QueueEmpty(&q))
	{
		if (q._head->_data != NULL)
			return 0;
		QueuePop(&q);
	}
	return 1;
}

//非递归前序遍历二叉树的思想为：a.访问他的左路节点b.访问左路节点的右子树
//将所有左路节点入栈的同时并访问，然后拿出栈顶节点，同时出栈顶节点，此时在访问出栈节点的右孩子，
//若右孩子为空直接栈顶节点，若不为空继续入站，访问出栈节点的左路节点和左路节点的右子树，
void BinaryTreePrevOrderNonR(BTNode* root)
{

	BTNode* cur = root;
	BTNode* top = NULL;
	Stack st;
	StackInit(&st, 3);
	while (cur != NULL || StackEmpty(&st) != 0)
	{
		while (cur != NULL)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}

//中序遍历的思路和前序遍历非递归很相似，也是分为左路节点和左路节点的右子树
//首先把左路节点入栈，不访问，当左路节点没有左左孩子时，那出栈顶节点并且访问，让后出栈顶接节点
//然后把栈节点的右孩子入栈，并且继续上面的过程。
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top = NULL;
	Stack st;
	StackInit(&st, 3);
	while (cur != NULL || StackEmpty(&st) != 0)
	{
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		StackPop(&st);
		printf("%c ", top->_data);
		cur = top->_right;
	}
	printf("\n");
}

//后序遍历的非递归遍历时，要判读它的右路节点是否已经被访问过，如果没有访问过就访问。
//首先把根节点入栈，如果根节点的左子树和右子树不存在，或者根节点的左子树和右子树已经
//访问过，直接拿出根节点访问，然后出栈节点，标记为上一个输出节点的prev，在把此时的站栈顶节点
//作为当前节点，若果不满足条件，就把根节点的左子树和右子树一次入栈，当前节点重置为栈顶节点，然后重复操作
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* top = NULL;
	BTNode* prev = NULL;
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 3);
	while (cur != NULL || StackEmpty(&st) != 0)
	{
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		top = StackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		else
		{
			cur = top->_right;
		}
	}

}

void TestBinaryTree1()
{
	char a[] = "ABD##E#H##CF##G##";
	int pindex = 0;
	BTNode* tree = BinaryTreeCreate(a, &pindex);
	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeInOrder(tree);
	printf("\n");

	BinaryTreePostOrder(tree);
	printf("\n");

	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelKSize(tree, 1));

	//printf("%c\n", BinaryTreeFind(tree, 1)); //这个函数调用没有调用出来

	BinaryTreeDestory(tree);
	tree = NULL;

}

void TestBinaryTree2()
{
	char a[] = "ABD##E#H##CF##G##";
	int pindex = 0;
	BTNode* tree = BinaryTreeCreate(a, &pindex);



	BinaryTreeLevelOrder(tree);  //层序遍历就是不出来?
	printf("\n");

	BinaryTreePrevOrderNonR(tree); //一般什么说在什么地方引用，大多数是因为函数调用错误。
	printf("\n");

	BinaryTreeInOrderNonR(tree);
	printf("\n");

	BinaryTreePostOrderNonR(tree);
	printf("\n");


	BinaryTreeComplete(tree);   //为什么调用不出来？
	printf("\n");

	BinaryTreeDestory(tree);
	tree = NULL;
}