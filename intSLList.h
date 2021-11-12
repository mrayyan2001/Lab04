//************************ intSLList.h **************************
// singly-linked list class to store integers
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(int el, IntSLLNode* ptr = 0) {
		info = el; next = ptr;
	}
	int info;
	IntSLLNode* next;
};

class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();
	bool isEmpty() {
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); // delete the head and return its info;
	int deleteFromTail(); // delete the tail and return its info;
	void deleteNode(int);
	bool isInList(int) const;
	void print();
	void insertAfter(int e, int v);
	void deleteAll(int v);
	void copyTo(IntSLList& dst);
	void reverse();
private:
	IntSLLNode* head, * tail;
};
#endif