﻿#include <iostream>
#include <fstream>
#include "Goods1.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include "Deque.h"
using namespace std;

bool testPushFront(Deque& aDeque, Goods* aGoods) {
	if (aDeque.getFront() == aGoods) {
		return true;
	}
	else {
		return false;
	}
}

bool testPushBack(Deque& aDeque, Goods* aGoods) {
	if (aDeque.getBack() == aGoods) {
		return true;
	}
	else {
		return false;
	}
}

bool testPopFront(int last, Deque& aDeque) {
	if (last == aDeque.getCountObj()) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> void testGetGoods(T& aGoods) {
	cout << aGoods << endl;
}

int main()
{
	MilkGoods milk;
	Goods pen;
	ChildGoods tank;
	testGetGoods(pen);
	testGetGoods(milk);
	testGetGoods(tank);
	
	Deque deque;
	Goods* goodsArmy[10];
	Goods Goods1;
	Goods Goods2;
	Goods Goods3;
	goodsArmy[0] = &Goods1;
	goodsArmy[1] = &Goods2;
	goodsArmy[2] = &Goods3;

	deque.pushBack(goodsArmy[0]);
	deque.getDeque();

	cout << endl << endl;

	deque.pushFront(goodsArmy[1]);
	deque.getDeque();
	if (testPushFront(deque, goodsArmy[1])) {
		cout << '\r' << '\r' << "Push-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-front-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	deque.pushBack(goodsArmy[2]);
	deque.getDeque();
	if (testPushBack(deque, goodsArmy[2])) {
		cout << '\r' << '\r' << "Push-back-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-back-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	int last = deque.getCountObj();
	deque.popFront();
	deque.getDeque();
	if (testPopFront(last, deque)) {
		cout << '\r' << '\r' << "Pop-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Pop-front-back-test was unsuccessful" << endl << endl;
	}

	cout << Goods::goodsCount << " unique goods are stored in the warehouse." << endl;
	cout << deque.getCountObj() << " unique goods are stored in the deque." << endl;
	return 0;
}
