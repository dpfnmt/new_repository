////#include<iostream>
////#include<string>
////#include<vector>
////
////using namespace std;
////
////#include <iostream>
////using namespace std;
////
////struct node{
////	int value;
////	node *next;
////};
////
////void add_node(node **head, int value) {
////	node *new_node = new node();
////	new_node->value = value;
////	new_node->next = NULL;
////	node *p_node = new node();
////	p_node = *head;
////	if (*head == NULL)
////		*head = new_node;
////	else {
////		while (p_node->next != NULL) {
////			p_node = p_node->next;
////		}
////		p_node->next = new_node;
////	}
////}
////
////
////void printcompart(node *head1, node* head2){
////
////	while (head1 != NULL && head2 != NULL){
////		if (head1->value > head2->value){
////			head2 = head2->next;
////		}
////		else if (head1->value < head2->value){
////			head1 = head1->next;
////		}
////		else{
////			cout << head1->value << " ";
////			head1 = head1->next;
////			head2 = head2->next;
////		}
////	}
////	cout << endl;
////}
////void display(node* head){
////	node * p = head;
////	while (p != NULL){
////		cout << p->value << " ";
////		p = p->next;
////	}
////}
//
//#include<iostream>
//#include<assert>
//using  namespace std;
//
//struct Node
//{
//	int value;
//	struct Node * Next;
//
//	Node(int data) :value(data), Next(NULL) {    }
//};
//
//
//void PrintCommonPart(Node *pHead1, Node *pHead2)
//{
//	assert(pHead1 && pHead2);
//
//	Node *pCur1 = pHead1;
//	Node *pCur2 = pHead2;
//
//	while (pCur1 != NULL && pCur2 != NULL)
//	{
//		if (pCur1->value < pCur2->value)
//		{
//			pCur1 = pCur1->Next;
//		}
//		else if (pCur1->value > pCur2->value)
//		{
//			pCur2 = pCur2->Next;
//		}
//		else
//		{
//			cout << pCur2->value << " ";
//
//			pCur1 = pCur1->Next;
//			pCur2 = pCur2->Next;
//		}
//	}
//
//}
//int main()
//{
//	node* node1 = NULL;
//	node* node2 = NULL;
//
//	int n, m,val1,val2;
//	cin >> n;
//	while (n > 0)
//	{
//		cin >> val1;
//		add_node(&node1, val1);
//		n--;
//	}
//	//display(node1);
//	cout << endl;
//
//	cin >> m;
//	while (m > 0)
//	{
//		cin >> val2;
//		add_node(&node2, val2);
//		m--;
//	}
//	//display(node2);
//
//	cout << "the common part is :";
//	printcompart(node1, node2);
//
//}
////struct ListNode
////{
////	int m_nvalue;
////	ListNode* m_pNext;
////};
////
////int GetListLength(ListNode* pHead);
////
////ListNode* FirstCommomNode(ListNode* pHead1, ListNode* pHead2)
////{
////	if (pHead1 == nullptr || pHead2 == nullptr)
////		return nullptr;
////	int Length_List1 = GetListLength(pHead1);
////	int Length_List2 = GetListLength(pHead2);
////	//判断哪个是长链表，计算需要移动的偏移量 默认是链表一
////	int Length_Offset = Length_List1 - Length_List2;;
////	ListNode* ListNodeLong = pHead1;
////	ListNode* ListNodeShort = pHead2;
////	if (Length_List1 < Length_List2)
////	{
////		Length_Offset = Length_List2 - Length_List1;
////		ListNodeLong = pHead2;
////		ListNodeShort = pHead1;
////	}
////	//将长链表偏移
////	for (int i = 0; i < Length_Offset; i++)
////	{
////		ListNodeLong = ListNodeLong->m_pNext;
////	}
////	//两个链表同步移动
////	while ((ListNodeLong != nullptr) && (ListNodeShort != nullptr) &&
////		(ListNodeLong != ListNodeShort))
////	{
////		ListNodeLong = ListNodeLong->m_pNext;
////		ListNodeShort = ListNodeShort->m_pNext;
////	}
////	return 	ListNodeShort;//返回公共节点
////}
////int GetListLength(ListNode* pHead)
////{
////	if (pHead == nullptr) return -1;
////	ListNode* pTemp = pHead;
////	unsigned int length = 0;
////	while (pTemp != nullptr)
////	{
////		length++;
////		pTemp = pTemp->m_pNext;
////	}
////	return length;
////}
//
//
//
////public class test_fifty_two {
////	public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2){
////		int length1 = getLength(pHead1);
////		int length2 = getLength(pHead2);
////
////		if (length1 == 0 || length2 == 0)
////			return null;
////
////		ListNode longListNode = null;
////		ListNode shortListNode = null;
////
////		if (length1 > length2){
////			longListNode = pHead1;
////			shortListNode = pHead2;
////		}
////		else{
////			longListNode = pHead2;
////			shortListNode = pHead1;
////		}
////
////		//两条链表相差多少个节点
////		int dif = Math.abs(length2 - length1);
////
////		//长链表先走dif个节点
////		for (int i = 0; i < dif; i++){
////			longListNode = longListNode.next;
////		}
////
////		//然后两个链表同时走
////		while (longListNode != null && shortListNode != null && longListNode != shortListNode){
////			shortListNode = shortListNode.next;
////			longListNode = longListNode.next;
////		}
////		return longListNode;
////	}
////
////	//获取链表的长度
////	private int getLength(ListNode pHead) {
////		if (pHead == null)return 0;
////
////		int length = 0;
////
////		while (pHead.next != null){
////			pHead = pHead.next;
////			length++;
////		}
////		return length;
////	}
////}

//#include <iostream>
//#include <string>
//using namespace std;
//
//struct node {
//	int value;
//	node *next;
//};
//
//node *add_node(node *head, int value) {
//	node *new_node = new node();
//	new_node->value = value;
//	new_node->next = NULL;
//	node *p_node = new node();
//	p_node = head;
//	if (head == NULL)
//		head = new_node;
//	else {
//		while (p_node->next != NULL) {
//			p_node = p_node->next;
//		}
//		p_node->next = new_node;
//	}
//	return head;
//}
//
//void print_common_part(node *head1, node *head2) {
//	while (head1 != NULL && head2 != NULL) {
//		if (head1->value < head2->value)
//			head1 = head1->next;
//		else if (head1->value > head2->value)
//			head2 = head2->next;
//		else {
//			cout << head1->value << ' ';
//			head1 = head1->next;
//			head2 = head2->next;
//		}
//	}
//}
//
//int main() {
//	node *head1 = NULL;
//	node *head2 = NULL;
//	string str, str_s;
//	cout << "please input the data of list1!" << endl;
//	getline(cin, str);
//	while (str.find(' ', 0) != string::npos) {
//		head1 = add_node(head1, atoi(str.substr(0, str.find(' ', 0)).c_str()));
//		str.erase(0, str.find(' ', 0) + 1);
//	}
//	head1 = add_node(head1, atoi(str.c_str()));
//	cout << "please input the data of list2!" << endl;
//	getline(cin, str);
//	while (str.find(' ', 0) != string::npos) {
//		head2 = add_node(head2, atoi(str.substr(0, str.find(' ', 0)).c_str()));
//		str.erase(0, str.find(' ', 0) + 1);
//	}
//	head2 = add_node(head2, atoi(str.c_str()));
//	cout << "the common part is: " << endl;
//	print_common_part(head1, head2);
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <list>
//#include <iterator>
//using namespace std;
//
//int main()
//{
//	int m, n, temp;
//	//输入两个链表的长度m,n
//	cin >> m >> n;
//	list<int> a;
//	list<int> b;
//
//	//向链表a和b中放元素
//	for (int i = 0; i<m; i++)
//	{
//		cin >> temp;
//		a.push_back(temp);
//	}
//
//	for (int i = 0; i<n; i++)
//	{
//		cin >> temp;
//		b.push_back(temp);
//	}
//	//使链表有序
//	a.sort();
//	b.sort();
//	//类似外排的方法来找出公共部分
//	list<int>::iterator p = a.begin();
//	list<int>::iterator q = b.begin();
//
//	while (p != a.end() && q != b.end())
//	{
//		if (*p < *q)
//			p++;
//		else if (*p > *q)
//			q++;
//		else
//		{
//			cout << *p << " " << endl;
//			p++;
//			q++;
//		}
//	}
//
//	system("pause");
//	return 0;
//}



#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int n ,i;
	while (cin >> n){
		if (n == 0)
			break;
		int* a = new int[n];
		for (i = 1; i<=n; i++)
			cin >> a[i];
		sort(a,a+n);
		for (int j = n; j > 0; j--)
		{
			int ret1 = n / 2;
			//cout << ret1 << endl;
			if (j > ret1 && j <= n)
			{
				//int ret1 = n / 2;
				cout << a[ret1] << endl;
			}
			else
			{
				//int ret1 = n / 2 - 2;
				cout << a[ret1 -1] << endl;
			}
		}
	}
	return 0;
}