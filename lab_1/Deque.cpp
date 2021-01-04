#include "Deque.h";

void Deque::getDeque() {
	cout << "Our deque:" << endl;
	if (countObj != 0) {
		Element* tool = front;
		for (int i = 0; i < countObj; i++) {
			cout << tool->obj->toString() << '\r';
			tool = tool->next;
		}
		cout << endl;
	}
	else {
		cout << "Deque is empty" << endl;
	}
}

void Deque::pushFront(Goods* aGoods) {
	if (countObj == 0) {
		front = new Element;
		back = front;
	}
	else {
		Element* tool = front;
		front = new Element;
		front->next = tool;
		tool->prev = front;
	}
	front->obj = aGoods;
	front->prev = NULL;
	countObj++;
}

void Deque::pushBack(Goods* aGoods) {
	if (countObj == 0) {
		back = new Element;
		front = back;
	}
	else {
		Element* tool = back;
		back = new Element;
		tool->next = back;
		back->prev = tool;
	}
	back->obj = aGoods;
	countObj++;
}

void Deque::popFront() {
	if (countObj != 0) {
		Element* tool = front;
		if (countObj == 1) {
			front = NULL;
			back = NULL;
		}
		else {
			front = front->next;
		}
		delete tool;
		countObj--;
	}
	else {
		cout << "Deque is empty" << endl;
	}
}

Deque::~Deque() {
	cout << "Deque deleted" << endl;
	int size = countObj;
	for (int i = 0; i < size; i++) {
		popFront();
	}
}
