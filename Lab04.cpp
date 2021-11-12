#include <iostream>
#include"intSLList.h"
using namespace std;

int main()
{

	IntSLList list, list2;
	/*list.addToHead(10);
	list.addToHead(3);
	list.addToHead(8);
	list.addToHead(18);
	list.addToHead(33);
	list.addToHead(5);*/

	/*list.addToHead(5);
	list.addToHead(1);
	list.addToHead(2);
	list.addToHead(5);
	list.addToHead(5);
	list.addToHead(5);
	list.addToHead(3);
	list.addToHead(4);
	list.addToHead(5);
	list.addToHead(5);*/

	list.addToHead(1);
	list.addToHead(2);
	list.addToHead(3);
	list.addToHead(4);

	list2.addToHead(18);
	list2.addToHead(33);
	list2.addToHead(5);

	while (true) {
		int choice;
		cout << "---------------------" << endl;
		cout << "[1]: Add to head" << endl;
		cout << "[2]: Add to tail" << endl;
		cout << "[3]: Delete from head" << endl;
		cout << "[4]: Delete from tail" << endl;
		cout << "[5]: Delete specific node" << endl;
		cout << "[6]: Is in list?" << endl;
		cout << "[7]: Print the list" << endl;
		cout << "[8]: Insert after" << endl;
		cout << "[9]: Delete all" << endl;
		cout << "[10]: Reverse" << endl;
		cout << "[11]: Copy to" << endl;
		cout << "[0]: Exit" << endl;
		cout << "your choice: ";
		cin >> choice;
		cout << "---------------------" << endl;
		if (choice == 0) break;

		int e;
		int v;
		IntSLList dst;
		dst.addToHead(5);
		dst.addToHead(0);
		dst.addToHead(9);
		dst.addToHead(10);
		switch (choice) {
		case 1:
			//int v;
			cout << "Enter the value: ";
			cin >> v;
			list.addToHead(v);
			break;
		case 2:
			//int v;
			cout << "Enter the value: ";
			cin >> v;
			list.addToTail(v);
			break;
		case 3:
			list.deleteFromHead();
			break;
		case 4:
			list.deleteFromTail();
			break;
		case 5:
			//int v;
			cout << "Enter the value: ";
			cin >> v;
			list.deleteNode(v);
			break;
		case 6:
			//int v;
			cout << "Enter the value: ";
			cin >> v;
			list.isInList(v);
			break;
		case 7:
			list.print();
			break;
		case 8:
			cout << "Enter the element: ";
			cin >> e;
			cout << "Enter th value: ";
			cin >> v;
			list.insertAfter(e, v);
			break;
		case 9:
			cout << "Enter th value: ";
			cin >> v;
			list.deleteAll(v);
			break;
		case 10:
			list.reverse();
			break;
		case 11:
			cout << "list1: ";
			list.print();
			cout << "list2: ";
			list2.print();
			list.copyTo(list2);
			cout << "copy list1 to list2...\n";
			cout << "list2: ";
			list2.print();
			break;
		default:
			cout << "sorry" << endl;
		}
	}
	return 1;
}
