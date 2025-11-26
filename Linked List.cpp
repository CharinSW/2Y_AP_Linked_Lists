#define _CRTDBG_MAP_ALLOC		// Ln 1 & 2 are for debugging memory leaks
#include <crtdbg.h>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int break_length = 100;

void br();

int main()
{
	LinkedList* list1 = new LinkedList();

	list1->add_to_tail(4);	// 4
	list1->add_to_head(3);	// 3, 4
	list1->add_to_head(2);	// 2, 3 ,4
	list1->add_to_head(1);	//	1, 2, 3, 4
	list1->add_to_tail(5);	// 1, 2, 3, 4, 5

	list1->print_list();

	list1->delete_from_head();	// 2, 3, 4, 5
	list1->print_list();

	list1->delete_from_tail();	// 2, 3, 4
	list1->print_list();

	list1->insert(1, 1, false);	// 2, 1, 3, 4
	list1->print_list();

	list1->delete_at(0);
	list1->print_list();

	_CrtDumpMemoryLeaks();
}


void br()
{
	for (int i = 0; i < break_length; i++)
	{
		cout << '-';
	}

	cout << endl;
}