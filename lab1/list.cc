#include <iostream>
#include "list.h"

List::List() {
	first = 0;
}

List::~List() {
	Node *p = first;
	Node *q = first;
	while (p) {
		q = p;
		p = p->next;
		delete q;
	}
}

bool List::exists(int d) const {
	Node* n = first;
	while (n) {
		if(n->value == d)
			return true;
		n = n->next;
	}
	return false;
}

int List::size() const {
	int size = 0;
	Node* n = first;
	while (n) {
		n = n->next;
		size++;
	}
	return size;
}

bool List::empty() const {
	return size() == 0;
}

void List::insertFirst(int d) {
	if (first) {
		first = new Node(d, first);
	} else {
		first = new Node(d, 0);
	}
}

void List::remove(int d, DeleteFlag df) {
	Node *p = first;
	Node *q = first;
	while (p) {
		int nVal = p->value;
		if ((nVal == d && df == List::DeleteFlag::EQUAL) || (nVal < d && df == List::DeleteFlag::LESS) || (nVal > d && df == List::DeleteFlag::GREATER)) {
			if (p == first)
				first = p->next;
			else {
				q->next = p->next;
			}
			delete p;
			return;
		}
		q = p;
		p = p->next;
	}
}

void List::print() const {
	Node* n = first;
	while (n) { 
		std::cout << n->value << " ";
		n = n->next;
	}
}

