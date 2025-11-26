#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList();

	bool is_empty();
	Node* get_node(int index);
	void add_to_tail(int value);
	void add_to_head(int value);
	void delete_from_tail();
	void delete_from_head();
	void insert(int value, int index, bool insert_pre);
	void delete_at(int index);
	void print_list();
};

