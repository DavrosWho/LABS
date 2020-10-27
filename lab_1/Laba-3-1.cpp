#include <iostream>
#include "Goods1.h"
using namespace std;

bool testAssignment(int strLength) {
	if (strLength > 100 || strLength < 1) {
		return false;
	}
	else {
		return true;
	}
}

bool testIncrementDecrement(char* prevDate, Goods aGoods) {
	int check = 0;
	for (int i = 0; i < 10; i++) {
		if (prevDate[i] != aGoods.getDate()[i]) {
			check++;
			break;
		}
	}
	
	if (check == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool testAddition(int answer, Goods aGoods, int add) {
	if (answer == aGoods.getQuantity() + add) {
		return true;
	}
	else {
		return false;
	}
}

bool testSubtraction(int subtrahend, Goods aGoods) {
	if (subtrahend <= aGoods.getQuantity()) {
		return true;
	}
	else {
		return false;
	}
}

bool testDouble(Goods aGoods, double aRCost) {
	if (double(aGoods.getRCost()) == aRCost) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	char* strGoods1 = new char[100];

	Goods GoodsTest;
	int len = 32;
	if (testAssignment(len)) {
		cout << "Can equal\nAssignment-test was successul\nOur Goods: ";
		GoodsTest = "Cocaine 100 110 120 20.30.2010 ";
		GoodsTest.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Can't equal. Line size must be less than 100\nAssignment-test was failed\n\n";
	}

	Goods Goods1;
	char* prev = new char[11];
	for (int i = 0; i < 10; i++) {
		prev[i] = Goods1.getDate()[i];
	}
	Goods1++;
	if (testIncrementDecrement(prev, Goods1)) {
		cout << "Increment-Decrement-test was successul\nOur Goods: ";
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Increment-Decrement-test was failed\n\n";
	}

	char* prev2 = new char[11];
	for (int i = 0; i < 10; i++) {
		prev2[i] = GoodsTest.getDate()[i];
	}
	GoodsTest--;
	if (testIncrementDecrement(prev2, GoodsTest)) {
		cout << "Increment-Decrement-test was successul\nOur Goods: ";
		GoodsTest.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Increment-Decrement-test was failed\n\n";
	}

	Goods Goods2;
	int add = 150;
	int answer = Goods2.getQuantity() + add;
	if (testAddition(answer, Goods2, add)) {
		cout << "Addition-test was successul\n" << add << " + " << Goods2.getQuantity() << " = " << answer;
		cout << "\n\n";
	}
	else {
		cout << "Addition-test was failed\n\n";
	}

	int subtrahend = 20;
	if (testSubtraction(subtrahend, Goods2)) {
		cout << "Subtration-test was successul\n" << Goods2.getQuantity() << " - " << subtrahend << " = " << answer;
		cout << "\n\n";
	}
	else {
		cout << "Subtration-test was failed. You can't subtract " << subtrahend << " from " << Goods2.getQuantity() << "\n\n";
	}

	double aRCost = 100;
	if (testDouble(Goods2, aRCost)) {
		cout << "Double-type-test was successul\n" << double(Goods2.getRCost()) << " = " << aRCost;
		cout << "\n\n";
	}
	else {
		cout << "Double-type-test was failed\n\n";
	}

	cout << Goods::goodsCount << " unique goods are stored in the warehouse.";
}
