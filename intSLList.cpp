//************************ intSLList.cpp **************************
#include <iostream>
#include "intSLList.h"

using namespace std;

IntSLList::~IntSLList() {
	for (IntSLLNode* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}
void IntSLList::addToHead(int el) {
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}
void IntSLList::addToTail(int el) {
	if (tail != 0) { // if list not empty;
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}
int IntSLList::deleteFromHead() {
	int el = head->info;
	IntSLLNode* tmp = head;
	if (head == tail) // if only one node in the list;
		head = tail = 0;
	else head = head->next;
	delete tmp;
	return el;
}
int IntSLList::deleteFromTail() {
	int el = tail->info;
	if (head == tail) { // if only one node in the list;
		delete head;
		head = tail = 0;
	}
	else { // if more than one node in the list,
		IntSLLNode* tmp; // find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp; // the predecessor of tail becomes tail;
		tail->next = 0;
	}
	return el;
}
void IntSLList::deleteNode(int el) {
	if (head != 0) // if nonempty list;
		if (head == tail && el == head->info) { // if only one
			delete head; // node in the list;
			head = tail = 0;
		}
		else if (el == head->info) {// if more than one node in the list
			IntSLLNode* tmp = head;
			head = head->next;
			delete tmp; // and old head is deleted;
		}
		else { // if more than one node in the list
			IntSLLNode* pred, * tmp;
			for (pred = head, tmp = head->next; // and a nonhead node
				tmp != 0 && !(tmp->info == el);// is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != 0) {
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
}
bool IntSLList::isInList(int el) const {
	IntSLLNode* tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

// -------------------------------------------------------------------------------

void IntSLList::print() { // O(n)
	for (IntSLLNode* temp = head; temp != 0; temp = temp->next) {
		cout << temp->info << " ";
	}
	cout << endl;
}

void IntSLList::insertAfter(int e, int v) { // O(n)
	if (isEmpty()) return;
	IntSLLNode* temp;
	for (temp = head; temp->info != e && temp->next != 0; temp = temp->next);

	temp->next = new IntSLLNode(v, temp->next);
	if (temp->next->next == 0) tail = temp->next; // if e is not in list or it is in the last node
}

void IntSLList::deleteAll(int v) {
	if (isEmpty()) return;

	//// method 1 O(n^2)
	//while (isInList(v)) deleteNode(v);

	// method 2 O(n)
	while (head->info == v) { // if v is in the head
		deleteFromHead();
	}
	while (tail->info == v) { // if v is in the tail
		deleteFromTail();
	}
	for (IntSLLNode* temp = head->next /*start after head*/, *pre = head; temp != tail /*skip tail*/; pre = temp, temp = temp->next) { // n - m
		while (temp->info == v) { // m
			pre->next = temp->next;
			delete temp;
			temp = pre->next;
		}
	}
}

void IntSLList::copyTo(IntSLList& dst) { // O(n)
	IntSLLNode* temp;
	for (temp = head; temp != 0; temp = temp->next) {
		dst.addToTail(temp->info);
	}
}

void IntSLList::reverse() {
	if (isEmpty()) return; // empty
	if (tail == head) return; // one node

	// method 1 using copy O(n)
	//IntSLList tempList;
	//while (!isEmpty()) { // copy the info from the list to tempList wihtout change order (start from head and use addToTail) and remove info from the list until list is being empty
	//	tempList.addToTail(head->info);
	//	deleteFromHead();
	//}
	//while (!tempList.isEmpty()) { // copy info from tempList to list with change order (start from head and use addToHead) and remove info from tempList until tempList is being empty
	//	addToHead(tempList.head->info);
	//	tempList.deleteFromHead();
	//}

	//// method 2 using reverse the ->next O(n)
	//IntSLLNode* prev = 0, * current = head, * next = head;
	//while (current != 0) {
	//	next = next->next;
	//	current->next = prev;
	//	prev = current;
	//	current = next;
	//}
	//// swap(head,tail)
	//IntSLLNode* temp = tail;
	//tail = head;
	//head = temp;

	// method 3 using swap O(n) ===> ×
	int* p = new int[0];
	int n = 0;

	// point to all info in the list
	int i = 0;
	for (IntSLLNode* temp = head; temp != 0; temp = temp->next, i++) {
		p[i] = temp->info;
		n = i;
	}

	// reverse pointer using swap between start(i) and end(j)
	for (int i = 0, j = n; j > i; i++, j--) {
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}

	// store reversed data to the list
	i = 0;
	for (IntSLLNode* temp = head; temp != 0; temp = temp->next, i++) {
		temp->info = p[i];
	}

	cout << "The list is reversed..." << endl;
}