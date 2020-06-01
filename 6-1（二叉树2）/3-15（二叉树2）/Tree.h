#ifndef __TREE_H__
#define __TREE_H__


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode* QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);

void QueuePush(Queue* q, QUDataType x);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QUDataType QueueFront(Queue* q);
QUDataType QueueBack(Queue* q);

typedef BTNode* STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackPrint(Stack* ps);



// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树

BTNode* BinaryTreeCreate(BTDataType* a, int* pindx);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree2();


#endif // __TREE_H__