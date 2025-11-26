#include "LinkedList.h"


LinkedList::LinkedList()
{
	head = tail = nullptr;
}


bool LinkedList::is_empty()
{
	return (head == nullptr && tail == nullptr);
}


Node* LinkedList::get_node(int index)
{
	Node* temp = new Node;
	temp = head;

	for (int i = 0; i < index; i++, temp = temp->next)
	{
		if (temp == nullptr)
		{
			return nullptr;
			break;
		}
	}

	return temp;
}


void LinkedList::add_to_tail(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = nullptr;

	// If list is empty
	if (is_empty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}


void LinkedList::add_to_head(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = nullptr;

	// If list is empty
	if (is_empty())
	{
		head = tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}


void LinkedList::delete_from_tail()
{
	if (!is_empty())
	{
		Node* prev = head;
		Node* temp = head->next;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			for (; temp != tail; temp = temp->next, prev = prev->next);

			prev->next = nullptr;
			tail = prev;

		}

		delete temp;
	}
	else
	{
		std::cout << "ERROR: Cannot delete from an empty list" << std::endl;
	}
}


void LinkedList::delete_from_head()
{
	// IF list isn't empty
	if (!is_empty())
	{
		Node* temp = head;

		// If there's only one element
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
		}

		delete temp;	// Remove old head
	}
	else
	{
		std::cout << "ERROR: Cannot delete from an empty list" << std::endl;
	}
}


void LinkedList::insert(int value, int index, bool insert_pre = false)
{
	if (get_node(index) != nullptr)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = nullptr;

		if (is_empty())
		{
			head = tail = temp;
		}
		else if (get_node(index) == head && insert_pre)
		{
			add_to_head(value);
		}
		else if (get_node(index) == tail && !insert_pre)
		{
			add_to_tail(value);
		}
		else if(insert_pre)
		{
			Node* prev = get_node(index - 1);
			temp->next = get_node(index);
			prev->next = temp;
		}
		// Post insert
		else
		{
			temp->next = get_node(index + 1);
			get_node(index)->next = temp;
		}
	}
	else
	{
		std::cout << "invalid index" << std::endl;
	}
}



void LinkedList::delete_at(int value)
{
	Node* prev = head;
	Node* temp = head->next;

	if (is_empty())
	{
		std::cout << "ERROR: Cannot delete from an empty list" << std::endl;
	}
	// If only one element
	else if (head == tail)
	{
		head = tail = nullptr;
	}
	else if (value == head->data)
	{
		delete_from_head();
	}
	else if (value == tail->data)
	{
		delete_from_tail();
	}
	else
	{
		for (; temp->data == value; temp = temp->next, prev = prev->next);

		prev->next = temp->next;
		temp->next = nullptr;	// This isn't required since ur deleting it below, but some languages don't have the delete function so then you have to do this
		delete temp;
	}
}


void LinkedList::print_list()
{
	Node* temp = head;

	std::cout << '[';

	for (; temp != nullptr; temp = temp->next)
	{
		if (temp != head)
		{
			std::cout << ", ";
		}

		std::cout << temp->data;
	}

	std::cout << ']' << std::endl;

	delete temp;
}