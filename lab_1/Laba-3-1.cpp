#include <iostream>
#include <fstream>
#include "Goods1.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include "Deque.h"
using namespace std;

bool testPushFront() {
	Deque <Goods> deque;
	Goods Goods1;
	Goods Goods2;
	Goods* Goods11 = &Goods2;
	deque.pushFront(Goods11);
	Goods11 = &Goods1;
	deque.getDeque();
	cout << "Push front function at work" << endl << endl;
	deque.pushFront(Goods11);
	deque.getDeque();
	if (deque.getFront() == Goods11) {
		return true;
	}
	else {
		return false;
	}
}

bool testPushBack() {
	Deque <Goods> deque;
	Goods Goods1;
	Goods Goods2;
	Goods* Goods11 = &Goods2;
	deque.pushBack(Goods11);
	Goods11 = &Goods1;
	deque.getDeque();
	cout << "Push back function at work" << endl << endl;
	deque.pushBack(Goods11);
	deque.getDeque();
	if (deque.getBack() == Goods11) {
		return true;
	}
	else {
		return false;
	}
}

bool testPopFront() {
	Deque <Goods> deque;
	Goods Goods1;
	Goods* Goods11 = &Goods1;
	deque.pushBack(Goods11);
	deque.getDeque();
	cout << "Pop front function at work" << endl << endl;
	int last = deque.getCountObj();
	deque.popFront();
	deque.getDeque();
	if (last - 1 == deque.getCountObj()) {
		return true;
	}
	else {
		return false;
	}
}

bool testGetGoods() {
	Goods pen;
	MilkGoods milk;
	ChildGoods tank;
	try {
		cout << pen << endl << milk << endl << tank << endl;
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

int main()
{
	if (testPushFront()) {
		cout << '\r' << '\r' << "Push-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-front-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	if (testPushBack()) {
		cout << '\r' << '\r' << "Push-back-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-back-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	if (testPopFront()) {
		cout << '\r' << '\r' << "Pop-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Pop-front-back-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	if (testGetGoods()) {
		cout << '\r' << '\r' << "Get-goods-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Get-goods-test was unsuccessful" << endl << endl;
	}

	cout << Goods::goodsCount << " unique goods are stored in the warehouse." << endl;
	return 0;
}
