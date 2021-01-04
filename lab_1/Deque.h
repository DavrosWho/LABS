#pragma once
#include <iostream>;
#include "Goods1.h";
#include "Milkgoods.h";
#include "ChildGoods.h";
using namespace std;

template <class T> class Deque {
	class Element {
	public:
		Element* prev = NULL;
		Element* next = NULL;
		Goods* obj;
	};
public:
	void getDeque();
	void pushFront(Goods* aGoods);
	void pushBack(Goods* aGoods);
	void popFront();
	Goods* getFront() { return front->obj; };
	Goods* getBack() { return back->obj; };
	int getCountObj() { return countObj; };
	~Deque();
private:
	Element* front = NULL;
	Element* back = NULL;
	int countObj = 0;
};

template <class T> void Deque<T>::getDeque() {
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

template <class T> void Deque<T>::pushFront(Goods* aGoods) {
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

template <class T> void Deque<T>::pushBack(Goods* aGoods) {
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

template <class T> void Deque<T>::popFront() {
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

template <class T> Deque<T>::~Deque() {
	cout << "Deque deleted" << endl;
	int size = countObj;
	for (int i = 0; i < size; i++) {
		popFront();
	}
}

