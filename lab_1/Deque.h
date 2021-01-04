#pragma once
#include <iostream>;
#include "Goods1.h";
#include "Milkgoods.h";
#include "ChildGoods.h";
using namespace std;

class Deque {
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
