#include<iostream>
using namespace std;
#define ll long long


struct Node
{
    string Name;
    ll Phone_Number;
    Node *prev;
    Node *next;
};


Node* split(Node *head)                         // Split a doubly linked list (DLL) into 2  of half sizes
{
	Node *fast = head,*slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	return temp;
}

Node *merge(Node *first, Node *second)           // Function to merge two linked lists
{
	if (!first) return second;
	if (!second) return first;

	if (first->Name < second->Name)
	{
		first->next = merge(first->next,second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first,second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

Node *MergeSort(Node *head)
{
	if (!head || !head->next) return head;
	Node *second = split(head);

	head = MergeSort(head);
	second = MergeSort(second);

	return merge(head,second);
}

void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

