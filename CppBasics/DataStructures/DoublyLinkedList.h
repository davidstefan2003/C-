#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

struct Student
{
	char* name;
	int age;
};

struct Node
{
	Student* info;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList
{
	int size;
	Node* first;
	Node* last;
};

Student* createStudent(const char* name, int age)
{
	Student* s = new Student;
	s->name = new char[strlen(name) + 1];
	strcpy(s->name, name);

	s->age = age;

	return s;
}

Node* createNode(const Student* info)
{
	Node* node = new Node;

	node->info = createStudent(info->name, info->age);
	node->next = nullptr;
	node->prev = nullptr;

	return node;
}

void insertStudentAtBack(DoublyLinkedList*& list, const Student* info)
{
	Node* node = createNode(info);
	if (list->first == nullptr || list->last == nullptr)
	{
		list->first = list->last = node;
		++list->size;
		return;
	}

	list->last->next = node;
	node->prev = list->last;
	list->last = node;

	++list->size;
}

void insertSorted(DoublyLinkedList*& list, const Student* info)
{
	Node* node = createNode(info);
	if (list->first == nullptr)
	{
		list->first = list->last = node;
		++list->size;
		return;
	}

	Node* it = list->first;
	while (it)
	{
		if (node->info->age < it->info->age)
		{
			++list->size;

			if (it->prev == nullptr)
			{
				list->first = node;

				it->prev = node;
				node->next = it;

				return;
			}

			node->prev = it->prev;
			it->prev->next = node;

			it->prev = node;
			node->next = it;

			return;
		}
		it = it->next;
	}

	insertStudentAtBack(list, info);
}

void insertStudentAtPos(DoublyLinkedList*& list, const Student* info, int pos)
{
	Node* node = createNode(info);

	if (pos == list->size)
	{
		insertStudentAtBack(list, info);
		return;
	}

	if (pos >= 0 && pos < list->size)
	{
		Node* it = list->first;
		while (pos > 0)
		{
			it = it->next;
			--pos;
		}

		node->next = it;
		node->prev = it->prev;
		it->prev = node;

		if (node->prev)
		{
			node->prev->next = node;
		}
		else
		{
			list->first = node;
		}

		++list->size;
	}

}

void printStudent(Student* s)
{
	std::cout << "Student{name=\'" << s->name << "\',age=" << s->age << "}\n";
}

void printList(DoublyLinkedList* list)
{
	if (list == nullptr) return;

	printStudent(list->first->info);
	Node* it = list->first;
	while (it->next)
	{
		it = it->next;
		printStudent(it->info);
	}

}

Node* findElement(const DoublyLinkedList* list, const char* name)
{
	if (list == nullptr)
	{
		return nullptr;
	}

	Node* it = list->first;
	while (it)
	{
		if (!strcmp(it->info->name, name))
		{
			return it;
		}

		it = it->next;
	}

	return nullptr;
}

void deleteStudent(DoublyLinkedList*& list, const char* name)
{
	if (Node* it = findElement(list, name))
	{
		--list->size;
		if (it->prev && it->next)
		{
			it->prev->next = it->next;
			it->next->prev = it->prev;
		}

		if (it->prev == nullptr && it->next == nullptr)
		{
			list->first = nullptr;
			list->last = nullptr;
		}
		else if (it->prev == nullptr)
		{
			list->first = it->next;
			list->first->prev = nullptr;
		}
		else if (it->next == nullptr)
		{
			list->last = it->prev;
			list->last->next = nullptr;
		}

		delete[] it->info->name;
		delete it->info;
		delete it;
	}
	else
	{
		std::cout << "Sugi pula ca nu exista\n";
	}

}

DoublyLinkedList* createList()
{
	DoublyLinkedList* list = new DoublyLinkedList;
	list->size = 0;
	list->first = nullptr;
	list->last = nullptr;

	return list;
}

void recursivePrint(const Node* n)
{
	if (n == nullptr)
	{
		return;
	}
	printStudent(n->info);
	recursivePrint(n->next);
}

int suma(const DoublyLinkedList* list)
{
	int suma = 0;

	Node* it = list->first;
	while (it)
	{
		suma += it->info->age;
		it = it->next;
	}

	return suma;
}

DoublyLinkedList* mergeSort(DoublyLinkedList*& l1, DoublyLinkedList*& l2)
{
	DoublyLinkedList* mergedList = createList();

	if (l1->first == nullptr || l2->first == nullptr)
	{
		return nullptr;
	}

	if (l1->first->info->age < l2->first->info->age)
	{
		mergedList->first = l1->first;
		l1->first = l1->first->next;
		l1->first->prev = nullptr;
		mergedList->first->next = nullptr;
	}
	else
	{
		mergedList->first = l2->first;
		l2->first = l2->first->next;
		l2->first->prev = nullptr;
		mergedList->first->next = nullptr;
	}

	Node* it = mergedList->first;

	while (l1->first && l2->first)
	{
		if (l1->first->info->age < l2->first->info->age)
		{
			it->next = l1->first;

			mergedList->last = l1->first;

			l1->first = l1->first->next;
			if (l1->first)
			{
				l1->first->prev->prev = it;
			}
			it->next->next = nullptr;
		}
		else
		{
			it->next = l2->first;

			mergedList->last = l2->first;

			l2->first = l2->first->next;
			if (l2->first)
			{
				l2->first->prev->prev = it;
			}
			it->next->next = nullptr;
		}

		it = it->next;
	}

	if (l1->first != nullptr)
	{
		l1->first->prev = mergedList->last;
		mergedList->last->next = l1->first;

		mergedList->last = l1->first;

		l1->first = nullptr;
	}

	if (l2->first != nullptr)
	{
		l2->first->prev = mergedList->last;
		mergedList->last->next = l2->first;

		mergedList->last = l2->first;

		l2->first = nullptr;
	}

	return mergedList;
}

bool isSorted(const DoublyLinkedList* list)
{
	Node* it = list->first;
	while (it->next)
	{
		if (it->info->age > it->next->info->age)
		{
			return false;
		}
		it = it->next;
	}

	return true;
}

void reverseList(DoublyLinkedList*& list)
{
	if (list->first == list->last || list->first == nullptr)
	{
		return;
	}

	// sliding pointers (framing window) / tailing pointers
	Node* it1 = nullptr;
	Node* it2 = list->first;

	while (it2)
	{
		Node* aux = it2->next;
		it2->next = it1;
		it2->prev = aux;

		it1 = it2;
		it2 = aux;
	}

	Node* aux = list->first;
	list->first = list->last;
	list->last = aux;
}
