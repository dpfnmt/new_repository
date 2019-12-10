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

int BinaryTreeLeafSize(BTNode* root)   //��������Ԫ�ظ���
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}


int BinaryTreeLevelKSize(BTNode* root, int k)  //��������k��Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (1 == k)  //���ﲻ���ж�root�ģ����ж����ڵ�ĸ����Ĵ�С���ڸ��ڵ��ʱ��ֻ��һ����
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ� 
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)   //��û��ʵ�ֳ���
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
// �ݹ����
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
// �ǵݹ����


// �������
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
// �ж϶������Ƿ�����ȫ������
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

//�ǵݹ�ǰ�������������˼��Ϊ��a.����������·�ڵ�b.������·�ڵ��������
//��������·�ڵ���ջ��ͬʱ�����ʣ�Ȼ���ó�ջ���ڵ㣬ͬʱ��ջ���ڵ㣬��ʱ�ڷ��ʳ�ջ�ڵ���Һ��ӣ�
//���Һ���Ϊ��ֱ��ջ���ڵ㣬����Ϊ�ռ�����վ�����ʳ�ջ�ڵ����·�ڵ����·�ڵ����������
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

//���������˼·��ǰ������ǵݹ�����ƣ�Ҳ�Ƿ�Ϊ��·�ڵ����·�ڵ��������
//���Ȱ���·�ڵ���ջ�������ʣ�����·�ڵ�û��������ʱ���ǳ�ջ���ڵ㲢�ҷ��ʣ��ú��ջ���ӽڵ�
//Ȼ���ջ�ڵ���Һ�����ջ�����Ҽ�������Ĺ��̡�
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

//��������ķǵݹ����ʱ��Ҫ�ж�������·�ڵ��Ƿ��Ѿ������ʹ������û�з��ʹ��ͷ��ʡ�
//���ȰѸ��ڵ���ջ��������ڵ���������������������ڣ����߸��ڵ�����������������Ѿ�
//���ʹ���ֱ���ó����ڵ���ʣ�Ȼ���ջ�ڵ㣬���Ϊ��һ������ڵ��prev���ڰѴ�ʱ��վջ���ڵ�
//��Ϊ��ǰ�ڵ㣬�����������������ͰѸ��ڵ����������������һ����ջ����ǰ�ڵ�����Ϊջ���ڵ㣬Ȼ���ظ�����
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

	//printf("%c\n", BinaryTreeFind(tree, 1)); //�����������û�е��ó���

	BinaryTreeDestory(tree);
	tree = NULL;

}

void TestBinaryTree2()
{
	char a[] = "ABD##E#H##CF##G##";
	int pindex = 0;
	BTNode* tree = BinaryTreeCreate(a, &pindex);



	BinaryTreeLevelOrder(tree);  //����������ǲ�����?
	printf("\n");

	BinaryTreePrevOrderNonR(tree); //һ��ʲô˵��ʲô�ط����ã����������Ϊ�������ô���
	printf("\n");

	BinaryTreeInOrderNonR(tree);
	printf("\n");

	BinaryTreePostOrderNonR(tree);
	printf("\n");


	BinaryTreeComplete(tree);   //Ϊʲô���ò�������
	printf("\n");

	BinaryTreeDestory(tree);
	tree = NULL;
}