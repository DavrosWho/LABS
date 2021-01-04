#include <iostream>
#include <fstream>
#include "Goods1.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include "Deque.h"
using namespace std;

template <class T> bool testPushFront(Deque<T>& aDeque, T* aGoods) {
	if (aDeque.getFront() == aGoods) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> bool testPushBack(Deque<T>& aDeque, T* aGoods) {
	if (aDeque.getBack() == aGoods) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> bool testPopFront(int last, Deque<T>& aDeque) {
	if (last == aDeque.getCountObj() + 1) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	Deque <Goods> deque;
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

	
	Deque <int> deque2;
	int* goodsArmy2[10];
	int intGoods1 = 1;
	int intGoods2 = 2;
	int intGoods3 = 33;
	goodsArmy2[0] = &intGoods1;
	goodsArmy2[1] = &intGoods2;
	goodsArmy2[2] = &intGoods3;

	deque2.pushBack(goodsArmy2[0]);
	deque2.getDeque();

	cout << endl << endl;

	deque2.pushFront(goodsArmy2[1]);
	deque2.getDeque();
	if (testPushFront(deque2, goodsArmy2[1])) {
		cout << '\r' << '\r' << "Push-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-front-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	deque2.pushBack(goodsArmy2[2]);
	deque2.getDeque();
	if (testPushBack(deque2, goodsArmy2[2])) {
		cout << '\r' << '\r' << "Push-back-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-back-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	last = deque2.getCountObj();
	deque2.popFront();
	deque2.getDeque();
	if (testPopFront(last, deque2)) {
		cout << '\r' << '\r' << "Pop-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Pop-front-back-test was unsuccessful" << endl << endl;
	}


	Deque <char> deque3;
	char* goodsArmy3[10];
	char charGoods1 = 'a';
	char charGoods2 = 'b';
	char charGoods3 = 'c';
	goodsArmy3[0] = &charGoods1;
	goodsArmy3[1] = &charGoods2;
	goodsArmy3[2] = &charGoods3;

	deque3.pushBack(goodsArmy3[0]);
	deque3.getDeque();

	cout << endl << endl;

	deque3.pushFront(goodsArmy3[1]);
	deque3.getDeque();
	if (testPushFront(deque3, goodsArmy3[1])) {
		cout << '\r' << '\r' << "Push-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-front-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	deque3.pushBack(goodsArmy3[2]);
	deque3.getDeque();
	if (testPushBack(deque3, goodsArmy3[2])) {
		cout << '\r' << '\r' << "Push-back-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Push-back-test was unsuccessful" << endl << endl;
	}

	cout << endl << endl;

	last = deque3.getCountObj();
	deque3.popFront();
	deque3.getDeque();
	if (testPopFront(last, deque3)) {
		cout << '\r' << '\r' << "Pop-front-test was successful" << endl << endl;
	}
	else {
		cout << '\r' << '\r' << "Pop-front-back-test was unsuccessful" << endl << endl;
	}
	
	cout << Goods::goodsCount << " unique goods are stored in the warehouse." << endl;
	cout << deque.getCountObj() << " unique goods are stored in the goods deque." << endl;
	cout << deque2.getCountObj() << " unique goods are stored in the data deque." << endl;
	cout << deque3.getCountObj() << " unique goods are stored in the data deque." << endl;
}