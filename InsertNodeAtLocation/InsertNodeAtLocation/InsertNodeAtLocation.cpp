#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		delete temp;
	}
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
	
	SinglyLinkedListNode *nodeToInsert = new SinglyLinkedListNode(data); 
	SinglyLinkedListNode *currentNode = head;

	if (head == nullptr)
		return nodeToInsert;
	if (position == 0)
	{
		nodeToInsert->next = head;
		return nodeToInsert;
	}
	while (position - 1 > 0) {
		currentNode = currentNode->next;
		position--;
	}

	nodeToInsert->next = currentNode->next;
	currentNode->next = nodeToInsert;
	return head;
}

int main()
{
	SinglyLinkedList* llist = new SinglyLinkedList();

	int llist_count;
	cin >> llist_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < llist_count; i++) {
		int llist_item;
		cin >> llist_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		llist->insert_node(llist_item);
	}

	int data;
	cin >> data;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int position;
	cin >> position;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

	print_singly_linked_list(llist_head, " ");
	cout << "\n";

	free_singly_linked_list(llist_head);

	return 0;
}


