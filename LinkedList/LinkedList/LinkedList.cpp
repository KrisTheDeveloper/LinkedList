// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
};

int main()
{
	Node *head = new Node();
	Node *second = new Node();
	Node *third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;

	return 0;
}
